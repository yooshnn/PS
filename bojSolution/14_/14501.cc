#include <bits/stdc++.h>
using namespace std;

vector<int> T(1, 0), P(1, 0);
int dp[17][2];
int res = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; ++i) {
		int p, q; cin >> p >> q;
		T.push_back(p); P.push_back(q);
	}
	for (int i = N; i >= 1; --i) {
		if (i + T[i] <= N + 1) dp[i][1] = max(dp[i + T[i]][0], dp[i + T[i]][1]) + P[i];
		dp[i][0] = max(dp[i + 1][0], dp[i + 1][1]);

		res = max({ res, dp[i][0], dp[i][1] });
	}

	cout << res;

	return 0;
}