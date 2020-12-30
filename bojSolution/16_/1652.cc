#include <bits/stdc++.h>
using namespace std;
	
int N;
char board[100][100];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int N; cin >> N;
	for (int r = 0; r < N; ++r) for (int c = 0; c < N; ++c) cin >> board[r][c];

	int res1 = 0, res2 = 0;
	
	for (int r = 0; r < N; ++r) {
		int cnt = 0;
		for (int c = 0; c < N; ++c) {
			if (board[r][c] == '.') cnt++;
			if (c == N-1 || board[r][c] == 'X') {
				if (cnt >= 2) res1++;
				cnt = 0;
			}
		}
	}
	for (int c = 0; c < N; ++c) {
		int cnt = 0;
		for (int r = 0; r < N; ++r) {
			if (board[r][c] == '.') cnt++;
			if (r == N-1 || board[r][c] == 'X') {
				if (cnt >= 2) res2++;
				cnt = 0;
			}
		}
	}
	cout << res1 << " " << res2;

	//cout << endl; system("pause");
}