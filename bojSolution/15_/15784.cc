#include <iostream>
using namespace std;

int N, a, b;
int board[1001][1001];

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

	cin >> N >> a >> b;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> board[i][j];
		}
	}

	bool ishappy = true;
	for (int i = 1; i <= N; ++i) {
		if (board[a][i] > board[a][b]) ishappy = false;
		if (board[i][b] > board[a][b]) ishappy = false;
	}
	cout << (ishappy ? "HAPPY" : "ANGRY");

	return 0;
}
