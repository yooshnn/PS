#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int
  N,
  board[20][20],
  dp[20][20][3];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int r = 1; r <= N; ++r) for (int c = 1; c <= N; ++c) {
    cin >> board[r][c];
    board[r][c] = 1 - board[r][c];
  }

  for (int c = 2; c <= N; ++c) {
    if (!board[1][c]) break;
    dp[1][c][0] = 1;
  }

  for (int r = 2; r <= N; ++r) for (int c = 1; c <= N; ++c) {
    dp[r][c][0] = board[r][c] * (dp[r][c-1][0] + dp[r][c-1][2]);
    dp[r][c][1] = board[r][c] * (dp[r-1][c][1] + dp[r-1][c][2]);
    dp[r][c][2] =
      (board[r][c] * board[r-1][c] * board[r][c-1]) *
      (dp[r-1][c-1][0] + dp[r-1][c-1][1] + dp[r-1][c-1][2]);
  }

  cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2];

  sad;
}