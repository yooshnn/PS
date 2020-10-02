#include <bits/stdc++.h>
using namespace std;

int N;
int board[100][100];
int utilBoard[100][100];

bool valid() {
	for (int k = 0; k < N; ++k) {
		for (int i = 1; i < N; ++i) {
			if (board[i - 1][k] >= board[i][k]) return false;
			if (k > 0) {
				if (board[i][k - 1] >= board[i][k]) return false;
			}
		}
	}
	return true;
}

void rot() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			utilBoard[i][j] = board[i][j];
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			board[i][j] = utilBoard[j][N - 1 - i];
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
		}
	}
	while (!valid()) rot();

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << board[i][j] << " ";
		} cout << "\n";
	}


	return 0;
}