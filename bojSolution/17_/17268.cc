#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll dp[5001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n; n /= 2;
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			dp[i] += dp[j] * dp[i - 1 - j];
			dp[i] %= 987654321;
		}
	}
	cout << dp[n];

	return 0;
}