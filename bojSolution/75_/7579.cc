#include <bits/stdc++.h>
using namespace std;

struct app {
	int m, c;
} apps[100];

int N, M;
int dp[100][10001]; // dp[app to close][cost] = memory

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int m_; cin >> m_; apps[i].m = m_;
	}
	for (int i = 0; i < N; ++i) {
		int c_; cin >> c_; apps[i].c = c_;
	}

	int res = 100000001;

	for (int i = 0; i <= 10000; ++i) {
		if (apps[0].c <= i) dp[0][i] = apps[0].m;
	}
	for (int i = 1; i < N; ++i) { // app id
		for (int j = 0; j <= 10000; ++j) { // cost
			if (apps[i].c > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - apps[i].c] + apps[i].m);

			if (dp[i][j] >= M) res = min(res, j);
		}
	}

	cout << res;

	return 0;
}