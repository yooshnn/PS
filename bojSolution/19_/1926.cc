#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int R, C;
int board[500][500];
int dir8[2][8]{ {0, -1, 0, 1, -1, -1, 1, 1}, {1, 0, -1, 0, 1, -1, -1, 1} };
bool dup[500][500];

int bfs(pii init) {
	int ret = 1;
	int cr, cc, nr, nc;
	queue<pii> que; dup[init.first][init.second] = true;
	for (que.push(init); !que.empty(); que.pop()) {
		tie(cr, cc) = que.front();
		for (int i = 0; i < 4; ++i) {
			nr = cr + dir8[0][i], nc = cc + dir8[1][i];
			if (nr < 0 || nc < 0 || nr >= R || nc >= C || dup[nr][nc] || board[nr][nc] == 0) continue; dup[nr][nc] = true;
			ret++;
			que.push({ nr, nc });
		}
	}
	return ret;
}

int main() {
	int res = 0, res2 = 0;
	cin >> R >> C;
	for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) cin >> board[r][c];
	for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) if (!dup[r][c] && board[r][c] == 1) res++, res2 = max(res2, bfs({ r, c }));
	cout << res << "\n" << res2;
}