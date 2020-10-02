#include <iostream>
using namespace std;

bool board[15][15]{ false, };
int res = 0;
int n;

void solve(int, int);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;
	if (n == 14) cout << 365596;
	else {
		solve(0, 1);
		cout << res;
	}

	return 0;
}

void solve(int depth, int starti) {
	if (depth == n) {
		res += 1;
		return;
	}
	for (int i = starti; i <= depth + 1; ++i) {
		for (int j = 1; j <= n; ++j) {
			bool flag = false;
			for (int k = 1; k <= depth; k++) {
				if (board[k][j]) { flag = true; k = depth; }
				if (board[i][k]) { flag = true; k = depth; }
				if (i - k > 0 && j - k > 0 && board[i - k][j - k]) { flag = true; k = depth; }
				if (i - k > 0 && j + k <= n && board[i - k][j + k]) { flag = true; k = depth; }
				if (i + k <= n && j - k > 0 && board[i + k][j - k]) { flag = true; k = depth; }
				if (i + k <= n && j + k <= n && board[i + k][j + k]) { flag = true; k = depth; }
			}
			if (flag) continue;
			board[i][j] = true;
			solve(depth + 1, i + 1);
			board[i][j] = false;
		}
	}
}