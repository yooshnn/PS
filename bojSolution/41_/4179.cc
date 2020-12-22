#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int R, C;
char board[1000][1000];
int dup[1000][1000]; // 1: jihoon 2: fire 
int dir4[2][4]{ {0, -1, 0, 1 }, {1, 0, -1, 0} };

int bfs(pii jhInit, vector<pii>& fireInit) {
	int tt = 0, ret = 1;
	queue<pii> queFire[2];
	queue<pii> queJh[2];

	for (pii p : fireInit) {
		queFire[0].push(p); dup[p.first][p.second] = 2;
	}
	queJh[0].push(jhInit);
	dup[jhInit.first][jhInit.second] = 1;

	int cr, cc, nr, nc;
	while (!(queFire[0].empty() && queFire[1].empty() && queJh[0].empty() && queJh[1].empty())) {

		while (!queJh[tt].empty()) {
			tie(cr, cc) = queJh[tt].front(); queJh[tt].pop();
			if (dup[cr][cc] == 2) continue;
			if (cr == 0 || cc == 0 || cr == R - 1 || cc == C - 1) return ret;
			for (int i = 0; i < 4; ++i) {
				nr = cr + dir4[0][i], nc = cc + dir4[1][i];
				if (nr == -1 || nc == -1 || nr == R || nc == C || board[nr][nc] == '#' || dup[nr][nc] != 0) continue;
				dup[nr][nc] = 1;
				queJh[1 - tt].push({ nr, nc });
			}
		}

		while (!queFire[tt].empty()) {
			tie(cr, cc) = queFire[tt].front(); queFire[tt].pop();
			for (int i = 0; i < 4; ++i) {
				nr = cr + dir4[0][i], nc = cc + dir4[1][i];
				if (nr == -1 || nc == -1 || nr == R || nc == C || board[nr][nc] == '#' || dup[nr][nc] == 2) continue;
				dup[nr][nc] = 2;
				queFire[1 - tt].push({ nr, nc });
			}
		}

		tt = 1 - tt;
		ret += 1;

	}

	return -1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	pii jihoon;
	vector<pii> fireInit;

	cin >> R >> C;
	for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
		cin >> board[r][c];
		if (board[r][c] == 'J') jihoon = { r, c };
		if (board[r][c] == 'F') fireInit.push_back({ r, c });
	}

	int req = bfs(jihoon, fireInit);
	if (req > 0) cout << req;
	else cout << "IMPOSSIBLE";
}