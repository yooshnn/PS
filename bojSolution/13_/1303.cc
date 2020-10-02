#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int C, R;
char board[100][100];
bool visit[100][100];
int w, b;

int bfs(int r, int c, char t) {
	int ret = 0;
	queue<pii> Q;
	Q.push({ r, c });
	while (!Q.empty()) {
		int cr = Q.front().first, cc = Q.front().second; Q.pop(); ret++;
		for (int i = 0; i < 4; ++i) {
			int nr = cr, nc = cc;
			if (i == 0) nr++; if (i == 1) nr--; if (i == 2) nc++; if (i == 3) nc--;
			if (nr < 0 || nc < 0 || nr >= R || nc >= C || board[nr][nc] != t || visit[nr][nc]) continue;
			visit[nr][nc] = true;
			Q.push({ nr, nc });
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> C >> R;
	for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) cin >> board[r][c];
	for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
		if (!visit[r][c]) {
			if (board[r][c] == 'W') {
				visit[r][c] = true;
				int req = bfs(r, c, 'W');
				w += req * req;
			}
			if (board[r][c] == 'B') {
				visit[r][c] = true;
				int req = bfs(r, c, 'B');
				b += req * req;
			}
		}
	}
	cout << w << " " << b;

	return 0;
}