#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using ll = long long;

ll dp[110][110]; // [n][g] separate at least g from n people 

ll solve(int n, int g) {
  if (dp[n][g] != 0) return dp[n][g];
  if (n < g) return dp[n][g] = 0;
  
  dp[n][g] = 1;
  for (int i = g; i <= n; ++i) dp[n][g] += solve(n-i, i);

  return dp[n][g];
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  for (int i = 5; i <= 100; ++i) {
    for (int j = 5; j <= i; ++j) solve(i, j);
  }

  int n; cin >> n; cout << dp[n][5];
}