#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int R, C;
char board[3002][3002];
ll dp[3002][3002];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> R >> C;
	for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) cin >> board[r][c];

	for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
		dp[r][c] = 1 + int(r - 1 >= 1 && board[r - 1][c] != 'E') * dp[r - 1][c] + int(c - 1 >= 1 && board[r][c - 1] != 'S') * dp[r][c - 1];
		dp[r][c] %= 1000000009;
	}

	cout << dp[R][C];
}