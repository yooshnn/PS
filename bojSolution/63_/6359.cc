#include <iostream>
#include <cstring>
using namespace std;

int T, n, r;
bool board[101];

int main() {
	cin >> T;
	while (T--) {
		r = 0;
		memset(board, 0, sizeof(board));
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; i * j <= n; ++j) {
				board[i * j] = !board[i * j];
			}
		}
		for (int i = 1; i <= n; ++i) {
			r += board[i];
		}
		cout << r << "\n";
	}

	return 0;
}