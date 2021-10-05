#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int cache[21][2097153];
int H;

/*
  B ■□■
  -

  A □■□
  B ■□■

  A □■□
  C ■■□
  -

  C ■■□ / □■■
  D ■■■
  -

  Impossible arrangement
  A - A

  Next state
  D -> B ( Separates the game )
  D -> C
  C -> A ( Separates the game, Is never adjacent to A )
*/

int calc(string);
int solve(string);

string readGame() {
  int H;
  string s, ret = "$";

  cin >> H;
  for (int i = 0; i < H; ++i) {
    cin >> s;
    if (s == ".I.") ret.push_back('A');
    else if (s == "I.I") ret.push_back('B');
    else if (s == "II." || s == ".II") ret.push_back('C');
    else ret.push_back('D');
  }
  ret.push_back('$');

  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  for (int i = 1; i <= 20; ++i) for (int j = 0; j < 2097153; ++j) {
    cache[i][j] = -1;
  }
  

  int TEST; cin >> TEST; while (TEST--) {
    string game = readGame();
    // cout << "INPUT: " << game << endl;
    int req = solve(game);
    cout << (req == 0 ? "Second\n" : "First\n");
    // cout << "ANSWER: " << (req == 0 ? "Second" : "First") << " (" << req << ")" << endl;
    cout.flush();
  }

  sad;
}

int calc(int game, int sz) {
  if (cache[sz][game] != -1) return cache[sz][game];

  int ret = 0;
  bool nxt[20]; memset(&nxt[0], 0, sizeof nxt);

  for (int i = 0; i < sz; ++i) {
    bool d = ((game >> i) & 1);

    if (d) { // D -> C, D -> B
      int u = 0, v = 0;

      game ^= (1 << i);
      nxt[calc(game, sz)] = true;

      for (int x = 0; x < i; ++x) {
        int y = x;
        u |= (game >> y) & 1;
        u <<= 1;
      }
      u >>= 1;
      for (int x = 0; x < sz-i-1; ++x) {
        int y = i+1+x;
        v |= (game >> y) & 1;
        v <<= 1;
      }
      v >>= 1;

      nxt[calc(u, i) ^ calc(v, sz-i-1)] = true;
      game ^= (1 << i);
    }
    else { // C -> A
      int tmp = 0, u = 0, v = 0;
      if (i != 0) {
        tmp ^= ((game >> (i-1)) & 1);
        for (int x = 0; x < i-1; ++x) {
          int y = x;
          u |= (game >> y) & 1;
          u <<= 1;
        }
        u >>= 1;
        tmp ^= calc(u, i-1);
      }
      if (i != sz-1) {
        tmp ^= ((game >> (i+1)) & 1);
        for (int x = 0; x < sz-i-2; ++x) {
          int y = i+2+x;
          v |= (game >> y) & 1;
          v <<= 1;
        }
        v >>= 1;
        tmp ^= calc(v, sz-i-2);
      }
      nxt[tmp] = true;
    }
  }

  for (int i = 0; ; ++i) {
    if (!nxt[i]) return cache[sz][game] = i;
    assert(i < 20);
  }
}

int solve(string game) {
  int ret = 0, las = 1;
  vector<pii> seg;

  for (int i = 1; i < game.size()-1; ++i) {
    char &b = game[i-1], &c = game[i], &d = game[i+1];
    if (c == 'B') c = '$';
    else if (c == 'A') {
      ret ^= ((b == 'D') ^ (d == 'D'));
      b = c = d = '$';
    }
  }

  for (int i = 1; i < game.size(); ++i) {
    if (game[i] == '$') {
      if (las != i) seg.push_back({las, i-1});
      las = i+1;
    }
  }

  for (pii i : seg) {
    int b = 0;
    for (char &c : game.substr(i.first, i.second - i.first + 1)) {
      b |= (c == 'D');
      b <<= 1;
    }
    b >>= 1;
    ret ^= calc(b, i.second - i.first + 1);
  }

  return ret;
}