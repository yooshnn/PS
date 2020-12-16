#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int R, C, K;
int dir8[2][8]{ {0, -1, -1, -1, 0, 1, 1, 1}, {1, 1, 0, -1, -1, -1, 0, 1} };
char board[100][100]; bool dup[100][100];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (cin >> R >> C) {
		if (R == 0) return 0;
		fill(&dup[0][0], &dup[0][0] + 10000, false);

		for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) cin >> board[r][c];

		int res = 0;
		for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) if (!dup[r][c] && board[r][c] == '@') {
			res++;
			queue<pii> que;
			for (que.push({ r, c }); !que.empty(); que.pop()) {
				int cr, cc; tie(cr, cc) = que.front();
				for (int i = 0; i < 8; ++i) {
					int nr = cr + dir8[0][i], nc = cc + dir8[1][i];
					if (nr < 0 || nc < 0 || nr == R || nc == C || dup[nr][nc] || board[nr][nc] == '*') continue;
					dup[nr][nc] = true; que.push({ nr, nc });
				}
			}
		}
		cout << res << "\n";
	}
}