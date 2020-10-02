#include <iostream>
#include <queue>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

char board[101][101];
bool visit[101][101];
int T;
int H, W, res;

void bfs(int r, int c) {
	queue<pii> Q;
	Q.push({ r, c });
	visit[r][c] = true;
	while (!Q.empty()) {
		pii cur = Q.front();
		int cr = cur.first, cc = cur.second;
		Q.pop();
		for (int i = 0; i < 4; ++i) {
			int nr = cr, nc = cc;
			if (i == 0) nc++; else if (i == 1) nc--; else if (i == 2) nr++; else if (i == 3) nr--;
			if (nr <= 0 || nc <= 0 || nr > H || nc > W || board[nr][nc]=='.') continue;
			if (visit[nr][nc]) continue;
			Q.push({ nr, nc });
			visit[nr][nc] = true;
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> T;
	while (T--) {
		res = 0;
		cin >> H >> W;
		for (int i = 1; i <= H; ++i) {
			for (int j = 1; j <= W; ++j) {
				cin >> board[i][j];
				visit[i][j] = false;
			}
		}
		for (int i = 1; i <= H; ++i) {
			for (int j = 1; j <= W; ++j) {
				if (!visit[i][j] && board[i][j]=='#') {
					bfs(i, j);
					res++;
				}
			}
		}
		cout << res << "\n";
	}

	

	return 0;
}
