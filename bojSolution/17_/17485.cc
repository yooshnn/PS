#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;

int R, C;
const int INF = 1e8;
int board[1010][1010], dp[1010][1010][3];

int request(int r, int c, int i) {
  if (c < 0 || c >= C) return INF;
  if (i == 0) return min(dp[r][c][1], dp[r][c][2]);
  if (i == 1) return min(dp[r][c][0], dp[r][c][2]);
  return min(dp[r][c][0], dp[r][c][1]);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  
  cin >> R >> C;

  for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) cin >> board[r][c];
  for (int c = 0; c < C; ++c) for (int i = 0; i < 3; ++i) dp[0][c][i] = board[0][c];

  for (int r = 1; r < R; ++r) for (int c = 0; c < C; ++c) {
    for (int i = 0; i < 3; ++i) {
      dp[r][c][i] = board[r][c] + request(r-1, c-1+i, i);
    }
  }

  int res = INF;
  for (int c = 0; c < C; ++c) for (int i = 0; i < 3; ++i) res = min(res, dp[R-1][c][i]);

  cout << res;
  
}