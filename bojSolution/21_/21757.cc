#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using ll = long long;

int n;
ll s[100010], psum[100010];
ll dp[100010][4];

ll solve() {
  ll pp = accumulate(&s[1], &s[n+1], 0);
  if (pp % 4 != 0) return 0;
  pp /= 4;

  for (int i = 1; i <= n; ++i) {

    dp[i][1] = dp[i-1][1];
    dp[i][2] = dp[i-1][2];
    dp[i][3] = dp[i-1][3];

    if (psum[i] == pp*3) {
      dp[i][3] += dp[i][2];
    }
    if (psum[i] == pp*2) {
      dp[i][2] += dp[i][1];
    }
    if (psum[i] == pp) {
      dp[i][1] += 1;
    }
  }

  return dp[n-1][3];

  
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

  cin >> n;

  for (int i = 1; i <= n; ++i) cin >> s[i];
  for (int i = 1; i <= n; ++i) psum[i] = psum[i-1] + s[i];

  cout << solve();

}