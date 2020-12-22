#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int, int> tup;

int R, C;
int board[1000][1000];
bool dup[2][1000][1000];
int dir4[2][4]{ {0, -1, 0, 1 }, {1, 0, -1, 0} };

int bfs(pii init, pii goal) {
	queue<tup> que;
	dup[0][init.first][init.second] = true;
	int cr, cc, p, t, nr, nc;
	for (que.push({ init.first, init.second, 0, 0 }); !que.empty(); que.pop()) {
		tie(cr, cc, p, t) = que.front();
		if (cr == goal.first && cc == goal.second) return t;
		for (int i = 0; i < 4; ++i) {
			nr = cr + dir4[0][i], nc = cc + dir4[1][i];
			if (nr == -1 || nc == -1 || nr == R || nc == C || dup[p][nr][nc]) continue;

			if (board[nr][nc] == 1) {
				if (p == 0) {
					dup[1][nr][nc] = true;
					que.push({ nr, nc, 1, t + 1 });
					continue;
				}
				else continue;
			}
			
			dup[p][nr][nc] = true;
			que.push({ nr, nc, p, t + 1 });
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	pii pp, qq;
	cin >> R >> C >> pp.first >> pp.second >> qq.first >> qq.second;
	pp.first--; qq.first--;
	pp.second--; qq.second--;

	for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) cin >> board[r][c];

	int req = bfs(pp, qq);
	if (req > 0) cout << req; else cout << -1;
}