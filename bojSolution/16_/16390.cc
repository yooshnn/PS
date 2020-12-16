#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int R, C;
char board[100][100];
int dir8[2][8]{ {0, -1, 0, 1, -1, -1, 1, 1}, {1, 0, -1, 0, 1, -1, -1, 1} };
bool dup[100][100];

void bfs(pii init) {
	int cr, cc, nr, nc;
	queue<pii> que; dup[init.first][init.second] = true;
	for (que.push(init); !que.empty(); que.pop()) {
		tie(cr, cc) = que.front();
		for (int i = 0; i < 8; ++i) {
			nr = cr + dir8[0][i], nc = cc + dir8[1][i];
			if (nr < 0 || nc < 0 || nr >= R || nc >= C || dup[nr][nc] || board[nr][nc] == '.') continue; dup[nr][nc] = true;
			que.push({ nr, nc });
		}
	}
}

int main() {
	int res = 0;
	cin >> R >> C;
	for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) cin >> board[r][c];
	for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) if (!dup[r][c] && board[r][c] == '#') bfs({ r, c }), res++;
	cout << res;
}