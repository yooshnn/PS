#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using pii = pair<int, int>;
using tup = tuple<int, int, int, int>;

const int INF = 2e8;
const int dir4[2][5] = {{0, -1, 0, 1, 0}, {1, 0, -1, 0, 0}};

int R, C;
int dup[40][40][40];
char board[40][40];

queue<pii> carInit[2];
bool car[40][40][40]; // {f, r, c}

pii frog;

void flush() {
  fill(&dup[0][0][0], &dup[0][0][0] + 40*40*40, INF);
  memset(&car[0][0][0], 0, sizeof(bool)*40*40*40);
}

void rd() {
  cin >> R >> C;

  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    char &tar = board[r][c];
    cin >> tar;

    if (tar == '&') frog = {r, c}, board[r][c] = '-';
    if (tar == '>') carInit[0].push({r, c}), board[r][c] = '-';
    if (tar == '<') carInit[1].push({r, c}), board[r][c] = '-';
  }
}

void procCar() {
  for (; !carInit[0].empty(); carInit[0].pop()) {
    auto [r, c] = carInit[0].front();
    for (int t = 0; t < C; ++t) {
      car[t][r][1 + (c + t + C - 1) % C] = true;
    }
  }
  for (; !carInit[1].empty(); carInit[1].pop()) {
    auto [r, c] = carInit[1].front();
    for (int t = 0; t < C; ++t) {
      car[t][r][1 + (c - t + C - 1) % C] = true;
    }
  }
}

int solve() {
  int ret = INF;

  priority_queue<tup, vector<tup>, greater<tup>> que;
  que.push({1, 0, frog.first, frog.second}); // weight f r c
  dup[0][frog.first][frog.second] = 1;

  while (!que.empty()) {
    auto [w, f, ro, co] = que.top();
    que.pop();
    if (board[ro][co] == '~') ret = min(ret, w);
    if (dup[f%C][ro][co] < w) continue;

    f += 1;
    for (int i = 0; i < 5; ++i) {
      int nr = ro + dir4[0][i], nc = co + dir4[1][i];
      if (nr < 1 || nr > R) continue;
      nc = 1 + (nc + C - 1) % C;
      if (car[f%C][nr][nc] || board[nr][nc] == 'T') continue;
      int nw = w + (board[nr][nc] == '-' ? 1 : 0);
      if (dup[f%C][nr][nc] > nw) {
        dup[f%C][nr][nc] = nw;
        que.push({nw, f, nr, nc});
      }
    }
  }

  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int TEST; cin >> TEST; while (TEST--) {
    
    flush();
    rd();
    procCar();

    int req = solve();
    if (req != INF) cout << req << '\n';
    else cout << "Impassable\n";
  }

}