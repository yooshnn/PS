#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;

const ll MOD = 1000000007;

int R, C, K;
bool emp[1010][1010];
ll dp[1010][1010];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> R >> C >> K;

  for (int r, c; K; K--) {
    cin >> r >> c;  
    emp[r][c] = true;
  }

  dp[1][1] = 1;

  for (int c = 1; c <= C; ++c) for (int r = 1; r <= R; ++r) {
    if (c&1) dp[r][c] += dp[r-1][c] + dp[r][c-1] + dp[r-1][c-1];
    else dp[r][c] += dp[r-1][c] + dp[r][c-1] + dp[r+1][c-1];
    dp[r][c] %= MOD;
    if (emp[r][c]) dp[r][c] = 0;
  }

  cout << dp[R][C];
  
  sad;
}