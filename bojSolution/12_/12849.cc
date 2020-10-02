#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll dp[8][100001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	dp[0][0] = 1;

	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		dp[0][i] = dp[1][i - 1] % mod + dp[5][i - 1] % mod; dp[0][i] %= mod;
		dp[1][i] = dp[0][i - 1] % mod + dp[2][i - 1] % mod + dp[5][i - 1] % mod; dp[1][i] %= mod;
		dp[2][i] = dp[1][i - 1] % mod + dp[3][i - 1] % mod + dp[5][i - 1] % mod + dp[6][i - 1] % mod; dp[2][i] %= mod;
		dp[3][i] = dp[2][i - 1] % mod + dp[4][i - 1] % mod + dp[6][i - 1] % mod; dp[3][i] %= mod;
		dp[4][i] = dp[3][i - 1] % mod + dp[7][i - 1] % mod; dp[4][i] %= mod;
		dp[5][i] = dp[0][i - 1] % mod + dp[1][i - 1] % mod + dp[2][i - 1] % mod + dp[6][i - 1] % mod; dp[5][i] %= mod;
		dp[6][i] = dp[2][i - 1] % mod + dp[3][i - 1] % mod + dp[5][i - 1] % mod + dp[7][i - 1] % mod; dp[6][i] %= mod;
		dp[7][i] = dp[4][i - 1] % mod + dp[6][i - 1] % mod; dp[7][i] %= mod;
	}

	cout << dp[0][n];

	return 0;
}