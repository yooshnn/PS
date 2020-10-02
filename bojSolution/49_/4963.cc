#include <iostream>
#include <string>
#include <queue>
#define pii pair<int,int>
using namespace std;

bool visit[50][50];
int board[50][50];
int R, C;

queue<pii> Q;

void bfs(int r, int c) {
	Q.push({ r,c });
	visit[r][c] = true;
	while (!Q.empty()) {
		pii cur = Q.front();
		Q.pop();
		int cr = cur.first, cc = cur.second;
		for (int i = 0; i < 8; ++i) {
			int nr = cr, nc = cc;
			if (i == 0) nr = cr + 1; if (i == 1) nr = cr - 1; if (i == 2) nc = cc + 1; if (i == 3) nc = cc - 1;
			if (i == 4) { nr = cr + 1; nc = cc + 1; } if (i == 5) { nr = cr - 1; nc = cc + 1; }
			if (i == 6) { nr = cr + 1; nc = cc - 1; } if (i == 7) { nr = cr - 1; nc = cc - 1; }
			if (nr < 0 || nc < 0 || nr >= R || nc >= C || visit[nr][nc] || board[nr][nc] == 0) continue;
			visit[nr][nc] = true;
			Q.push({ nr,nc });
		}
	}
}

int main() {
	while (true) {
		cin >> C >> R;

		if (R == C && R == 0) break;

		for (int i = 0; i < 50; ++i) {
			for (int j = 0; j < 50; ++j) {
				visit[i][j] = false;
			}
		}

		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				cin >> board[i][j];
			}
		}

		int res = 0;

		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if (!visit[i][j] && board[i][j] == 1) {
					bfs(i, j);
					res++;
				}
			}
		}

		cout << res << "\n";
	}

	return 0;
}