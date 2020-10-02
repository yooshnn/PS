#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char board[520];
int N, p = -1;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	string input; getline(cin, input); N = input.size();
	for (int i = 0; i < N; ++i) {
		board[i] = input[i];
	}
	while (p++ < N) {
		if (board[p] != 'X') continue;
		int b = 0;
		while (++b < 4) {
			if (p + b >= N || board[p + b] == '.') break;
		}
		if (b == 2) {
			board[p] = 'B';
			board[p + 1] = 'B';
			p += 1;
			continue;
		}
		else if (b == 4) {
			board[p] = 'A';
			board[p + 1] = 'A';
			board[p + 2] = 'A';
			board[p + 3] = 'A';
			p += 3;
			continue;
		}
		else {
			cout << -1;
			return 0;
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << board[i];
	}

	return 0;
}