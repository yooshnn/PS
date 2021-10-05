#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;

int
  N, x, res = 0,
  dp[600][600];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; ++i) for (int j = 1; j <= i; ++j) {
    cin >> x;
    dp[i][j] = x + max(dp[i-1][j], dp[i-1][j-1]);
    res = max(res, dp[i][j]);
  }

  cout << res;
  
  sad;
}
