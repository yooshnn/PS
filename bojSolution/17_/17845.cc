#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;

int N, K;
int dp[1010][10010];
int I[1010], T[1010];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> K;
  for (int i = 1; i <= K; ++i) cin >> I[i] >> T[i];
  
  for (int k = 1; k <= K; ++k) {
    for (int t = 1; t <= N; ++t) {
      if (T[k] > t) dp[k][t] = dp[k-1][t];
      else dp[k][t] = max(dp[k-1][t], dp[k-1][t-T[k]] + I[k]);
    }
  }

  cout << dp[K][N];

}