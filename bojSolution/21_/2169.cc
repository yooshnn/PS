#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using ll = long long;

const ll INF = 2e9;

int R, C;
ll board[1010][1010];
ll dp[3][1010][1010];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> R >> C;

  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    cin >> board[r][c];
  }

  for (int c = 1; c <= C; ++c) dp[2][1][c] = dp[2][1][c-1] + board[1][c];
  for (int r = 2; r <= R; ++r) {
    dp[0][r][0] = dp[1][r][C+1] = -INF;
    for (int c = 1; c <= C; ++c) {
      dp[0][r][c] = max(dp[0][r][c-1], dp[2][r-1][c]) + board[r][c];
    }
    for (int c = C; c >= 1; --c) {
      dp[1][r][c] = max(dp[1][r][c+1], dp[2][r-1][c]) + board[r][c];
    }
    for (int c = 1; c <= C; ++c) {
      dp[2][r][c] = max(dp[0][r][c], dp[1][r][c]);
    }
  }

  cout << dp[2][R][C];

}