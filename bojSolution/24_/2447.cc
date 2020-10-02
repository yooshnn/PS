#include <iostream>
using namespace std;

bool board[2187][2187]{ false };

void f(int n, int p) {
	for (int i = 0; i < p / 3; ++i) {
		for (int j = 0; j < p / 3; ++j) {

			int center = 0;
			for (int k = i; k < i + p; k += p / 3) {
				for (int l = j; l < j + p; l += p / 3) {
					if (center++ != 4) board[k][l] = board[i][j];
					else board[k][l] = false;
				}
			}

		}
	}
	if (n == p) return;
	f(n, p * 3);
}

int main() {
	board[0][0] = true;

	int n;
	cin >> n;

	f(n, 1);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j]) cout << "*";
			else cout << " ";
		}
		cout << "\n";
	}

	return 0;
}