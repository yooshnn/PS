#include <bits/stdc++.h>
using namespace std;

int n, res = 2147483647;
int cost[1001][3];
int dp[1001][3];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	
	for (int c = 0; c < 3; ++c) {
		memset(dp, 0, sizeof(dp));
		dp[1][0] = 30000; dp[1][1] = 30000; dp[1][2] = 30000;
		dp[1][c] = cost[1][c];
		for (int i = 2; i <= n; ++i) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
		}
		dp[n][c] = 2147483647;
		res = min(res, min(dp[n][2], min(dp[n][0], dp[n][1])));
	}

	cout << res;

	return 0;
}