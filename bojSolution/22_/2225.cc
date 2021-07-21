#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using ll = long long;

int N, K;
ll dp[300][300];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> K;

  for (int j = 1; j <= K; ++j) {
    dp[0][j] = 1;
  }

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= K; ++j) {
      dp[i][j] = dp[i-1][j] + dp[i][j-1];
      dp[i][j] %= 1000000000;
    }
  }

  cout << dp[N][K];
}