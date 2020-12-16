#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tup;

int R, C;
int board[500][500];
int dir8[2][8]{ {0, -1, 0, 1, -1, -1, 1, 1}, {1, 0, -1, 0, 1, -1, -1, 1} };
bool dup[500][500];
priority_queue<tup> pque;

int bfs(pii init) {
	int cr, cc, nr, nc;
	int ret = 1;
	queue<pii> que; dup[init.first][init.second] = true;
	for (que.push(init); !que.empty(); que.pop()) {
		tie(cr, cc) = que.front();
		for (int i = 0; i < 4; ++i) {
			nr = cr + dir8[0][i], nc = cc + dir8[1][i];
			if (nr < 0 || nc < 0 || nr >= R || nc >= C || dup[nr][nc] || board[nr][nc] > board[cr][cc] || board[nr][nc] < 2) continue; dup[nr][nc] = true;
			que.push({ nr, nc });
			ret++;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int res = 0, cnt = 0;
	cin >> R >> C;
	for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
		cin >> board[r][c];
		if (board[r][c] > 1) {
			pque.push({ board[r][c], r, c });
			cnt++;
		}
	}

	if (pque.empty() || get<0>(pque.top()) < 2) {
		cout << 0; return 0;
	}

	while (cnt > 0) {
		tup cur;
		do {
			cur = pque.top(); pque.pop();
		} while (dup[get<1>(cur)][get<2>(cur)]);
		cnt -= bfs({ get<1>(cur), get<2>(cur) });
		res++;
	}
	cout << res;
}