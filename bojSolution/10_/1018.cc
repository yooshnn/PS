#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	char board[50][50];
	int res = 64;

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i <= N-8; ++i) {
		for (int j = 0; j <= M-8; ++j) {
			int caseB = 0, caseW = 0;
			for (int k = i; k < i+8; ++k) {
				for (int l = j; l < j+8; ++l) {
					if ((k + l) % 2 == 0) {
						if (board[k][l] != 'B') caseB++;
					}
					else {
						if (board[k][l] != 'W') caseB++;
					}
				}
			}
			for (int k = i; k < i+8; ++k) {
				for (int l = j; l < j+8; ++l) {
					if ((k + l) % 2 == 0) {
						if (board[k][l] != 'W') caseW++;
					}
					else {
						if (board[k][l] != 'B') caseW++;
					}
				}
			}
			res = min(res, min(caseB, caseW));
		}
	}
	cout << res;

	return 0;
}