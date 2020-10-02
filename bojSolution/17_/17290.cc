#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int r, c, res = 100000;
	bool board[10][10];
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) board[i][j] = false;
	}

	cin >> r >> c; r--; c--;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			char input; cin >> input;
			if (input == 'o')
			for (int k = 0; k < 10; ++k) {
				board[i][k] = true;
				board[k][j] = true;
			}
		}
	}

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (board[i][j]) continue;
			res = min(res, abs(i - r) + abs(j - c));
		}
	}

	cout << res;

	return 0;
}