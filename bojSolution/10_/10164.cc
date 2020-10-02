#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
int dp[16][16];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);

	cin >> N >> M >> K;

	dp[1][1] = 1;
	if (K == 0) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				if (i == 1 && j == 1) continue;
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		cout << dp[N][M];
		return 0;
	}

	int KR = (K - 1) / M + 1, KC = (K - 1) % M + 1;

	for (int i = 1; i <= KR; ++i) {
		for (int j = 1; j <= KC; ++j) {
			if (i == 1 && j == 1) continue;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	int res = dp[KR][KC];
	dp[KR][KC] = 1;
	for (int i = KR; i <= N; ++i) {
		for (int j = KC; j <= M; ++j) {
			if (i == KR && j == KC) continue;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	cout << res * dp[N][M];

	return 0;
}