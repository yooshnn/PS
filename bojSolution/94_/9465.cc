#include <iostream>
#include <algorithm>
using namespace std;

int T, n;
int s[2][100000];
int dp[2][100000];

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> s[0][i];
		for (int i = 0; i < n; ++i) cin >> s[1][i];

		if (n >= 1) {
			dp[0][0] = s[0][0];
			dp[1][0] = s[1][0];
		}
		if (n >= 2) {
			dp[0][1] = s[1][0] + s[0][1];
			dp[1][1] = s[0][0] + s[1][1];
		}
		
		for (int i = 2; i < n; ++i) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + s[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + s[1][i];
		}

		int res = 0;

		for (int i = 0; i < n; ++i) {
			if (dp[0][i] > res) res = dp[0][i];
			if (dp[1][i] > res) res = dp[1][i];
		}

		cout << res << "\n";
	}

	return 0;
}