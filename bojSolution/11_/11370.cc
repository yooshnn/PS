#include <iostream>
#include <string>
#include <queue>
#define pii pair<int,int>
using namespace std;

char board[1000][1000];
bool visit[1000][1000];

string line;
int R, C, res;
queue<pii>Q;

void bfs(int r, int c) {
	visit[r][c] = true;
	Q.push({ r, c });
	while (!Q.empty()) {
		pii cur = Q.front();
		Q.pop();
		int cr = cur.first, cc = cur.second;
		for (int i = 0; i < 4; ++i) {
			int nr = cr, nc = cc;
			if (i == 0) nc = cc + 1; else if (i == 1) nc = cc - 1; else if (i == 2) nr = cr + 1; else if (i == 3) nr = cr - 1;
			if (nc < 0 || nr < 0 || nc >= C || nr >= R || visit[nr][nc] || board[nr][nc] == '.') continue;
			Q.push({ nr, nc });
			visit[nr][nc] = true;
			board[nr][nc] = 'S';
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

	while (1) {

		cin >> C >> R;

		if (C == R && C == 0) break;

		for (int i = 0; i < 1000; ++i) {
			for (int j = 0; j < 1000; ++j) {
				visit[i][j] = false;
			}
		}

		for (int i = 0; i < R; ++i) {
			cin >> line;
			for (int j = 0; j < C; ++j) {
				board[i][j] = line[j];
			}
		}

		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if (!visit[i][j] && board[i][j] == 'S') {
					bfs(i, j);
				}
			}
		}

		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				cout << board[i][j];
			}cout << "\n";
		}

	}

	return 0;
}