#include <iostream>
#include <string>
using namespace std;

char board[500][500];
int R, C;

void solve() {
	bool flag = true;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (board[i][j] == 'S') {
				if (i > 0 && board[i - 1][j] == 'W') flag = false;
				if (i + 1 <= R - 1 && board[i + 1][j] == 'W') flag = false;
				if (j > 0 && board[i][j - 1] == 'W') flag = false;
				if (j + 1 <= C - 1 && board[i][j + 1] == 'W') flag = false;
			}
		}
	}
	cout << int(flag) << "\n";
	if (flag) {
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				cout << board[i][j];
			}cout << endl;
		}
	}
}

int main() {
	cin >> R >> C;
	cin.ignore();
	cin.clear();
	string line;
	for (int i = 0; i < R; ++i) {
		getline(cin, line);
		for (int j = 0; j < C; ++j) {
			char temp = line[j];
			board[i][j] = temp;
			if (board[i][j] == '.') board[i][j] = 'D';
		}
	}

	solve();
	return 0;
}