#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
short candy[1001][1001];
int dp[1001][1001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> candy[i][j];
		}
	}
	dp[1][1] = candy[1][1];
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (i == 1 && j == 1) continue;
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + candy[i][j]);
			dp[i][j] = max(dp[i][j], dp[i][j - 1] + candy[i][j]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + candy[i][j]);
		}
	}
	cout << dp[N][M];

	return 0;
}