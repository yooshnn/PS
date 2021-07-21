#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;

int dp[10010];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  for (int i = 0; i <= 10000; ++i) {
    dp[i] = 1;
  }
  for (int i = 2; i <= 10000; ++i) {
    dp[i] += dp[i-2];
  }
  for (int i = 3; i <= 10000; ++i) {
    dp[i] += dp[i-3];
  }

  int TEST; cin >> TEST; while (TEST--) {
    int N; cin >> N;
    cout << dp[N] << '\n';
  }

}