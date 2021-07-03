#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;

struct Tup {
  int r, c, m;
  bitset<6> keys;

  Tup(int _r, int _c) {
    r = _r;
    c = _c;
    m = 0;
    keys.reset();
  }
  Tup(int _r, int _c, int _m, bitset<6> _keys) {
    r = _r;
    c = _c;
    m = _m;
    keys = _keys;
  }
};
// pos, moves, bitset

int R, C;
char board[60][60];
bool dup[60][60][70];
int dir4[2][4] {{0, -1, 0, 1}, {1, 0, -1, 0}};
queue<Tup> que;

bool oob(int r, int c) {
  return (r < 1 || c < 1 || r > R || c > C);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

  cin >> R >> C;
  
  for (int r = 1; r <= R; ++r) {
    for (int c = 1; c <= C; ++c) {
      cin >> board[r][c];
      if (board[r][c] == '0') que.emplace(r, c), board[r][c] = '.', dup[r][c][0] = true;
    }
  }

  for (; !que.empty(); que.pop()) {
    Tup cur = que.front();
    int &r = cur.r, &c = cur.c, &m = cur.m;

    if (board[r][c] == '1') {
      cout << m;
      return 0;
    }

    for (int i = 0; i < 4; ++i) {
      int nr = r + dir4[0][i], nc = c + dir4[1][i];
      bitset<6> keys_ = cur.keys;
      if (oob(nr, nc) || board[nr][nc] == '#') continue;
      if ('a' <= board[nr][nc] && board[nr][nc] <= 'f') keys_[board[nr][nc] - 'a'] = true;
      if ('A' <= board[nr][nc] && board[nr][nc] <= 'F' && keys_[board[nr][nc] - 'A'] == false) continue;
      int state = keys_.to_ulong();
      if (dup[nr][nc][state]) continue;
      dup[nr][nc][state] = true;
      que.push(Tup(nr, nc, m + 1, keys_));
    }

  }
  cout << -1;

}