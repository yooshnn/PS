#include <bits/stdc++.h>
using namespace std;

int dp[1002][1002];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string src, tar; cin >> src >> tar;

	for (int i = 0; i <= src.size(); ++i) dp[i][0] = i;
	for (int i = 0; i <= tar.size(); ++i) dp[0][i] = i;

	for (int i = 1; i <= src.size(); ++i) {
		for (int j = 1; j <= tar.size(); ++j) {
			if (src[i - 1] == tar[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
		}
	}

	cout << dp[src.size()][tar.size()];
}