#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tup;

int board[50][50];
int res[50][50];
int dir[2][8] { {0, -1, -1, -1, 0, 1, 1, 1}, {1, 1, 0, -1, -1, -1, 0, 1} };

int R, C;

void bfs(tup init) {
	queue<tup> que;
	bool dup[50][50]; fill(&dup[0][0], &dup[0][0] + 50 * 50, 0);
	dup[get<1>(init)][get<2>(init)] = true;
	res[get<1>(init)][get<2>(init)] = 0;
	for (que.push(init); !que.empty(); que.pop()) {
		int ct, cr, cc; tie(ct, cr, cc) = que.front();
		for (int i = 0; i < 8; ++i) {
			int nr = cr + dir[0][i], nc = cc + dir[1][i];
			if (nr < 0 || nc < 0 || nr >= R || nc >= C || dup[nr][nc]) continue;
			dup[nr][nc] = true; res[nr][nc] = min(res[nr][nc], ct);
			que.push({ ct + 1, nr, nc });
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R >> C; fill(&res[0][0], &res[0][0] + 50 * 50, 2147483647);
	for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
		int temp; cin >> temp; if (temp) bfs({ 1, r, c });
	}
	int T = 0;
	for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) T = max(T, res[r][c]);
	cout << T;
}