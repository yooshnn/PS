#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tup;

int R, C;
int O, F, r1, c1, r2, c2;

bool visit[101][101];
int board[101][101];

bool bfs(int row, int col, int f) {
	queue<tup> Q;
	Q.push({ row, col, f });
	while (!Q.empty()) {
		int cr, cc, cf;
		tie(cr, cc, cf) = Q.front(); Q.pop();
		if (cr == r2 && cc == c2) return true;
		if (cf == 0) continue;
		for (int i = 0; i < 4; ++i) {
			int nr = cr, nc = cc, nf = cf;
			if (i == 0) nc++; if (i == 1) nc--; if (i == 2) nr++; if (i == 3) nr--;
			if (nr <= 0 || nc <= 0 || nr > R || nc > C) continue;
			if (board[nr][nc] - board[cr][cc] > nf) continue;
			if (visit[nr][nc]) continue;
			visit[nr][nc] = true;
			Q.push({ nr, nc, nf - 1 });
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int TEST; cin >> TEST; while (TEST--) {

		cin >> R >> C >> O >> F >> r1 >> c1 >> r2 >> c2;
		for (int r = 0; r <= R; ++r) for (int c = 0; c <= C; ++c) {
			board[r][c] = 0;
			visit[r][c] = false;
		}

		for (int o = 0; o < O; ++o) {
			int r, c, l; cin >> r >> c >> l; board[r][c] = l;
		}

		cout << (bfs(r1, c1, F) ? "잘했어!!" : "인성 문제있어??") << "\n";

	}

	return 0;
}