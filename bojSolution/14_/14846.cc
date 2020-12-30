#include <bits/stdc++.h>
using namespace std;

int N, Q;
int board[302][302];
int dp[302][302][11];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int r = 1; r <= N; ++r) for (int c = 1; c <= N; ++c) cin >> board[r][c];

	for (int r = 1; r <= N; ++r) {
		for (int c = 1; c <= N; ++c) {
			for (int i = 1; i <= 10; ++i) {
				dp[r][c][i] = (board[r][c] == i ? 1 : 0) + dp[r - 1][c][i] + dp[r][c - 1][i] - dp[r - 1][c - 1][i];
			}
		}
	}

	cin >> Q;
	int r0, c0, r1, c1, res, sub;
	while (Q--) {
		cin >> r0 >> c0 >> r1 >> c1;
		res = sub = 0;
		for (int i = 1; i <= 10; ++i) {
			sub = dp[r0 - 1][c1][i] + dp[r1][c0 - 1][i] - dp[r0 - 1][c0 - 1][i];
			//if (dp[r1][c1][i] - sub < 0) assert(0);
			if (dp[r1][c1][i] - sub > 0) res += 1;
		}
		cout << res << "\n";
	}
}