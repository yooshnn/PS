#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int
  N,
  dp[2][500001]; // max height at diff j

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;

  memset(&dp[0][0], -1, sizeof(int)*2*500001);
  dp[0][0] = 0;

  for (int i = 1; i <= N; ++i) {
    int h; cin >> h;

    for (int j = 0; j <= 500000; ++j) {
      if (dp[0][j] != -1) {
        dp[1][j+h] = max(dp[1][j+h], dp[0][j] + h);
        
        if (j >= h) dp[1][j-h] = max(dp[1][j-h], dp[0][j]);
        if (h >= j) dp[1][h-j] = max(dp[1][h-j], dp[0][j] - j + h);
      }
    }

    for (int j = 0; j <= 500000; ++j) dp[0][j] = max(dp[0][j], dp[1][j]);
  }

  cout << (dp[0][0] == 0 ? -1 : dp[0][0]);
  
  sad;
}