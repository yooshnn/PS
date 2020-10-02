#include <iostream>
using namespace std;

int board[1025][1025];
long long dp[1025][1025];

int N, M;
int xa, xb, ya, yb;
long long res, sum;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			dp[i][j] = dp[i][j - 1] + board[i][j];
		}
	}
	for (int i = 2; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			dp[i][j] += dp[i - 1][j];
		}
	}

	while (M--) {
		cin >> xa >> ya >> xb >> yb;
		cout << dp[xb][yb] - dp[xb][ya-1] - dp[xa-1][yb] + dp[xa-1][ya-1] << "\n";
	}

	return 0;
}