#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using tup = tuple<int, int, int, int>;

int R, C, K;
char board[1010][1010];
int dup[1010][1010][12][2];
int dir4[2][4] {{0, -1, 0, 1}, {1, 0, -1, 0}};

bool oob(int r, int c) {
  return (r < 0 || c < 0 || r >= R || c >= C);
}

int solve() {
  int nr, nc;
  queue<tup> que;
  dup[0][0][0][1] = 1;
  for (que.push({0, 0, 0, 1}); !que.empty(); que.pop()) {
    auto [r, c, k, t] = que.front();
    if (dup[r][c][k][1-t&1] > t+1) {
      que.push({r, c, k, t+1}), dup[r][c][k][1-t&1] = t+1;
    }
    for (int i = 0; i < 4; ++i) {
      nr = r + dir4[0][i], nc = c + dir4[1][i];
      if (oob(nr, nc)) continue;
      if (board[nr][nc] == '0') {
        if (dup[nr][nc][k][1-t&1] > t+1) {
          que.push({nr, nc, k, t+1}), dup[nr][nc][k][1-t&1] = t+1;
        }
      }
      else if (k < K && t&1) {
        if (dup[nr][nc][k+1][1-t&1] > t+1) {
          que.push({nr, nc, k+1, t+1}), dup[nr][nc][k+1][1-t&1] = t+1;
        }
      }
    }
  }
  int ret = 2e8;
  for (int i = 0; i <= K; ++i) ret = min({ret, dup[R-1][C-1][i][0], dup[R-1][C-1][i][1]});
  return (ret == 2e8 ? -1 : ret);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  
  cin >> R >> C >> K;
  for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
    cin >> board[r][c];
    for (int i = 0; i <= K; ++i) dup[r][c][i][0] = dup[r][c][i][1] = 2e8;
  }

  cout << solve();
}