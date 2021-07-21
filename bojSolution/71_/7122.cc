#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using ll = long long;

int
  R, C,
  dp[2][20][20],
  board[20][20];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> C >> R;
  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    cin >> board[r][c];
  }

  dp[0][0][1] = 1;
  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    if (board[r][c] == 5) continue;
    else if (board[r][c] == 4) dp[0][r][c] = dp[0][r-1][c];
    else if (board[r][c] == 3) dp[1][r][c] = dp[1][r][c-1];
    else if (board[r][c] == 2) dp[0][r][c] = dp[1][r][c-1];
    else if (board[r][c] == 1) dp[1][r][c] = dp[0][r-1][c];
    else dp[0][r][c] = dp[1][r][c] = dp[0][r-1][c] + dp[1][r][c-1];
  }

  cout << dp[1][R][C];
  
}