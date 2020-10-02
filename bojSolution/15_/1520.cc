#include <iostream>
#define l long
using namespace std;

int R, C;
l res;
l board[501][501];
int dp[501][501];

int solve(int r, int c) {
	if (r == 0 && c == 0) return 1;
	if (dp[r][c] != -1) return dp[r][c];
	else dp[r][c] = 0;

	for (int i = 0; i < 4; ++i) {
		int nr = r, nc = c;
		if (i == 0) nr++; else if (i == 1) nr--; else if (i == 2) nc++; else nc--;
		if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
		if (board[nr][nc] <= board[r][c]) continue;
		dp[r][c] += solve(nr, nc);
	}

	return dp[r][c];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R >> C;
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			cin >> board[r][c];
			dp[r][c] = -1;
		}
	}

	cout << solve(R - 1, C - 1);

	return 0;
}