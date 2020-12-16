#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tup;

int R, C;
char board[100][100];
int dir8[2][8]{ {0, -1, 0, 1, -1, -1, 1, 1}, {1, 0, -1, 0, 1, -1, -1, 1} };
bool dup[100][100];

int bfs(tup init) {
	int cr, cc, t, nr, nc; tie(cr, cc, t) = init;
	queue<tup> que; dup[cr][cc] = true;
	for (que.push(init); !que.empty(); que.pop()) {
		tie(cr, cc, t) = que.front();
		if (board[cr][cc] == 'B') return t;
		for (int i = 0; i < 4; ++i) {
			nr = cr + dir8[0][i], nc = cc + dir8[1][i];
			if (nr < 0 || nc < 0 || nr >= R || nc >= C || dup[nr][nc] || board[nr][nc] == '*') continue; dup[nr][nc] = true;
			que.push({ nr, nc, t + 1 });
		}
	}
}

int main() {
	int res = 0;
	cin >> R >> C;
	for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) cin >> board[r][c];
	for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
		if (board[r][c] == 'C') {
			cout << bfs({ r, c, 0 }); return 0;
		}
	}
}