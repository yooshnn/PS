#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int, pii> tup; // 시간 R C 방향,가속도

int R, C;
int board[100][100];
int dup[100][100][4][15];
int bfsDir[2][4] = { {0, -1, 0, 1}, {1, 0, -1, 0} };

int bfs() {
	priority_queue<tup, vector<tup>, greater<tup>> que;
	que.push({ 0, 0, 0, {-1, -1} });
	while (!que.empty()) {
		int ct, cr, cc; pii vel;
		tie(ct, cr, cc, vel) = que.top(); que.pop();
		if (cr == R - 1 && cc == C - 1) return ct;

		for (int i = 0; i < 4; ++i) {
			int nr = cr, nc = cc;
			pii nvel;
			if (i != vel.first) {
				nr += bfsDir[0][i], nc += bfsDir[1][i];
				if (nr < 0 || nc < 0 || nr >= R || nc >= C || (board[nr][nc] != 0 && board[nr][nc] <= ct + 1) || dup[nr][nc][i][1]) continue;
				nvel = { i, 1 };
			}
			else {
				nr += bfsDir[0][i] * (vel.second + 1), nc += bfsDir[1][i] * (vel.second + 1);
				if (nr < 0 || nc < 0 || nr >= R || nc >= C || (board[nr][nc] != 0 && board[nr][nc] <= ct + 1) || dup[nr][nc][i][vel.second + 1]) continue;
				bool good = true;
				//cout << "cur : " << cr << " " << cc << " " << nvel.second + 1 << "\n";
				if (i == 0 || i == 2) {
					for (int j = cc + bfsDir[1][i]; j != nc; j += bfsDir[1][i]) {
						//cout << "checking r[" << nr << "] c[" << j << "]\n";
						if (board[nr][j] != 0 && board[nr][j] < ct + 1) good = false;
					}
				}
				if (i == 1 || i == 3) {
					for (int j = cr + bfsDir[0][i]; j != nr; j += bfsDir[0][i]) {
						//cout << "checking r[" << j << "] c[" << nc << "]\n";
						if (board[j][nc] != 0 && board[j][nc] < ct + 1) good = false;
					}
				}
				if (!good) continue;
				nvel = { i, vel.second + 1 };
			}
			dup[nr][nc][i][nvel.second] = true;
			que.push({ ct + 1, nr, nc, nvel });
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R; C = R;

	if (R == 1) {
		cout << 0; return 0;
	}

	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			cin >> board[r][c];
		}
	}
	int req = bfs();
	if (req == -1) cout << "Fired";
	else cout << req;

}