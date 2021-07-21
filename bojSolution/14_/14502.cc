#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using pii = pair<int, int>;

int R, C, res;
int board[10][10], block[10][10];
vector<pii> init;

int dir4[2][4] = { {0, -1, 0, 1}, {1, 0, -1, 0} };
bool oob(int r, int c) { return r < 1 || c < 1 || r > R || c > C; }

int solve() {
  int ret = 0;

  bool dup[10][10];
  memset(&dup[0][0], 0, sizeof(bool)*10*10);

  queue<pii> que;
  for (pii &i : init) que.push(i), dup[i.first][i.second] = true;

  for (; !que.empty(); que.pop()) {
    auto [ro, co] = que.front();
    for (int i = 0; i < 4; ++i) {
      int nr = ro + dir4[0][i], nc = co + dir4[1][i];
      if (oob(nr, nc) || dup[nr][nc] || board[nr][nc] != 0 || block[nr][nc]) continue;
      dup[nr][nc] = true;
      que.push({nr, nc});
    }
  }

  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    if (board[r][c] != 0 || dup[r][c] || block[r][c]) continue;
    ret += 1;
  }

  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> R >> C;
  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    cin >> board[r][c];
    if (board[r][c] == 2) init.push_back({r, c});
  }

  for (int i = 0; i < R*C-2; ++i) {
    for (int j = i+1; j < R*C-1; ++j) {
      for (int k = j+1; k < R*C; ++k) {
        pii p[3] = {{1 + i/C, 1 + i%C}, {1 + j/C, 1 + j%C}, {1 + k/C, 1 + k%C}};
        
        bool cont = false;
        for (int l = 0; l < 3; ++l) if (board[p[l].first][p[l].second] != 0) cont = true;
        if (cont) continue;

        for (int l = 0; l < 3; ++l) block[p[l].first][p[l].second] = true;
        res = max(res, solve());
        for (int l = 0; l < 3; ++l) block[p[l].first][p[l].second] = false;
      }
    }
  }

  cout << res;

}