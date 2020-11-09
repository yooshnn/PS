#include <bits/stdc++.h>
using namespace std;

int dp[50001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;

	fill(begin(dp), end(dp), 5);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; ++i) {
		for (int j = 1; i - j * j >= 0; ++j) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[n];

	return 0;
}