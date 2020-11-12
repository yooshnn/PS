#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;

int R, C;
int board[102][102];
int dp[102][102];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R >> C;
	for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) cin >> board[r][c];

	dp[1][1] = board[1][1];
	for (int c = 2; c <= C; ++c) for (int r = 1; r <= R; ++r) {
		int req = max({ dp[r - 1][c - 1], dp[r][c - 1], dp[r + 1][c - 1] });
		if (req != 0) dp[r][c] = board[r][c] + req;
	}

	cout << dp[R][C];
}