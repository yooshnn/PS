#include <iostream>
using namespace std;
int board[5][5], dup[1000000];
int res = 0;

void solve(int depth, int x, int y, int sum) {
	if (depth == 6) {
		if (dup[sum] == false) {
			dup[sum] = true;
			res++;
		}
		return;
	}
	sum = sum*10 + board[x][y];
	for (int i = 0; i < 4; ++i) {
		int nx = x+ (i == 0) - (i == 2);
		int ny = y+ (i == 1) - (i == 3);
		if ((nx >= 0 && nx <= 4) && (ny >= 0 && ny <= 4)) solve(depth + 1, nx, ny, sum);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			solve(0, i, j, 0);
		}
	}
	
	cout << res;

	return 0;
}