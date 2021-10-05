#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int
  N, res,
  board[1010][1010],
  dp[1010][1010][3];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int r = 1; r <= N; ++r) for (int c = 1; c <= N; ++c) {
    cin >> board[r][c];
  }

  for (int r = 1; r <= N; ++r) for (int c = 1; c <= N; ++c) {
    int i = board[r][c], j = (1+board[r][c])%3, k = (2+board[r][c])%3;

    if (i == 0 || max(dp[r-1][c][k], dp[r][c-1][k]) != 0) {
      dp[r][c][i] = 1 + max(dp[r-1][c][k], dp[r][c-1][k]);
    }
    
    dp[r][c][j] = max(dp[r-1][c][j], dp[r][c-1][j]);
    dp[r][c][k] = max(dp[r-1][c][k], dp[r][c-1][k]);
  }

  cout << max({ dp[N][N][0], dp[N][N][1], dp[N][N][2] });

  sad;
  
}