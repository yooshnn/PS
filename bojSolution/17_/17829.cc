#include <bits/stdc++.h>
using namespace std;

int n, s = 1;
int board[1024][1024];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < n; ++c) {
			cin >> board[r][c];
		}
	}

	while (s < n) {
		s *= 2;
		for (int r = 0; r < n; r += s) {
			for (int c = 0; c < n; c += s) {
				int temp[4];
				temp[0] = board[r][c];
				temp[1] = board[r + s / 2][c];
				temp[2] = board[r][c + s / 2];
				temp[3] = board[r + s / 2][c + s / 2];
				sort(temp, temp + 4);
				board[r][c] = temp[2];
			}
		}
	}

	cout << board[0][0];

	return 0;
}