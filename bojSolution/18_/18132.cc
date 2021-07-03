#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, e;
ll dp[6000];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	dp[0] = 1;
	for (int i = 1; i <= 5010; ++i) {
		for (int j = 0; j < i; ++j) {
			dp[i] += dp[j] * dp[i - 1 - j];
			dp[i] %= (1000000007);
		}
	}
	
  cin >> n;
  while (n--) {
    cin >> e;
    cout << dp[e+1] << '\n';
  }

}