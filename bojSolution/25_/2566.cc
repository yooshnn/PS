#include <iostream>
using namespace std;

int m=0, mx, my;
int board[10][10];

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

	for (int i = 1; i < 10; ++i) {
		for (int j = 1; j < 10; ++j) {
			cin >> board[i][j];
			if (board[i][j] > m) {
				m = board[i][j];
				mx = j;
				my = i;
			}
		}
	}
	cout << m << "\n" << my << " " << mx;

	return 0;
}
