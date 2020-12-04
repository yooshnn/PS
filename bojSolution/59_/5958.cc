#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, res;
char board[1001][1001];
int bfsDir[2][4] { {0, -1, 0, 1},{1, 0, -1, 0} };

void bfs(int br, int bc) {
	queue<pii> que; que.push({ br, bc });
	board[br][bc] = '.';
	while (!que.empty()) {
		int cr, cc; tie(cr, cc) = que.front(); que.pop();
		for (int i = 0; i < 4; ++i) {
			int nr = cr + bfsDir[0][i], nc = cc + bfsDir[1][i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N || board[nr][nc] == '.') continue;
			board[nr][nc] = '.';
			que.push({ nr, nc });
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int r = 0; r < N; ++r) for (int c = 0; c < N; ++c) cin >> board[r][c];
	for (int r = 0; r < N; ++r) for (int c = 0; c < N; ++c) {
		if (board[r][c] == '*') {
			bfs(r, c);
			res++;
		}
	}
	cout << res;

}