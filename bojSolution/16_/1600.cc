#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int, int> tup;

int R, C, K;
int board[200][200];
int dirKnight[2][8]{ {-1, 1, 2, 2, 1, -1, -2, -2}, {2, 2, 1, -1, -2, -2, -1, 1 } };
int dir4[2][4]{ {0, -1, 0, 1}, {1, 0, -1, 0} };
bool dup[200][200][32];

int bfs(tup init) {
	int ret = 1e8;
	int cr, cc, ck, ct, nr, nc; tie(cr, cc, ck, ct) = init;
	queue<tup> que; dup[cr][cc][ck] = true;
	for (que.push(init); !que.empty(); que.pop()) {
		tie(cr, cc, ck, ct) = que.front();
		if (cr == R - 1 && cc == C - 1) {
			ret = min(ret, ct); continue;
		}
		if (ck > 0) {
			for (int i = 0; i < 8; ++i) {
				nr = cr + dirKnight[0][i], nc = cc + dirKnight[1][i];
				if (nr < 0 || nc < 0 || nr >= R || nc >= C || dup[nr][nc][ck - 1] || board[nr][nc] == 1) continue; dup[nr][nc][ck - 1] = true;
				que.push({ nr, nc, ck - 1, ct + 1 });
			}
		}
		for (int i = 0; i < 4; ++i) {
			nr = cr + dir4[0][i], nc = cc + dir4[1][i];
			if (nr < 0 || nc < 0 || nr >= R || nc >= C || dup[nr][nc][ck] || board[nr][nc] == 1) continue; dup[nr][nc][ck] = true;
			que.push({ nr, nc, ck, ct + 1 });
		}
	}
	return ret;
}

int main() {
	int res = 0;
	cin >> K >> C >> R;
	for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) cin >> board[r][c];
	int req = bfs({ 0, 0, K, 0 });
	if (req == 1e8) cout << -1;
	else cout << req;
}