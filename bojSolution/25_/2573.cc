#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

int board[301][301];
int decr[301][301];
bool visit[301][301];

int R, C;
int cnt;

void bfs(int r, int c) {
	queue<pii> Q;
	Q.push({ r, c });
	visit[r][c] = true;
	while (!Q.empty()) {
		pii cur = Q.front(); Q.pop();
		int curR = cur.first, curC = cur.second;
		for (int i = 0; i < 4; ++i) {
			int newR = curR, newC = curC;
			if (i == 0) newR++; else if (i == 1) newR--; else if (i == 2) newC++; else newC--;
			if (newR <= 0 || newC <= 0 || newR > R || newC > C) continue;
			if (visit[newR][newC] || board[newR][newC] <= 0) continue;
			visit[newR][newC] = true;
			Q.push({ newR, newC });
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

	cin >> R >> C;
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			cin >> board[i][j];
		}
	}

	int k = 0;
	while (++k) {
		memset(visit, false, sizeof(visit));

		cnt = 0;
		for (int i = 1; i <= R; ++i) {
			for (int j = 1; j <= C; ++j) {
				if (!visit[i][j] && board[i][j] != 0) {
					bfs(i, j);
					cnt++;
				}
			}
		}

		if (cnt >= 2) { cout << k - 1; return 0; }
		else if (cnt == 0) { cout << 0; return 0; }

		for (int i = 2; i < R; ++i) {
			for (int j = 2; j < C; ++j) {
				if (board[i][j] == 0) continue;
				decr[i][j] = max(0, board[i][j] - (board[i - 1][j] == 0) - (board[i + 1][j] == 0) - (board[i][j + 1] == 0) - (board[i][j - 1] == 0));
			}
		}

		for (int i = 2; i < R; ++i) {
			for (int j = 2; j < C; ++j) {
				board[i][j] = decr[i][j];
			}
		}
	}

	return 0;
}