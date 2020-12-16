#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tup;

int R, C;
int dir8[2][8]{ {0, -1, 0, 1, -1, -1, 1, 1}, {1, 0, -1, 0, 1, -1, -1, 1} };
char board[100][100]; bool dup[100][100];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R; C = R;
	for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) cin >> board[r][c];

	priority_queue<tup, vector<tup>, greater<tup>> que; dup[0][0] = true;
	que.push({ 0, 0, 0 });
	while (!que.empty()) {
		int w, cr, cc; tie(w, cr, cc) = que.top(); que.pop();
		if (cr == R - 1 && cc == C - 1) {
			cout << w; return 0;
		}
		for (int i = 0; i < 4; ++i) {
			int nr = cr, nc = cc;
			if (i & 1) {
				while (0 <= nr + dir8[0][i] && nr + dir8[0][i] < R) {
					nr += dir8[0][i];
					if (board[nr][nc] == '#') break;
					if (!dup[nr][nc]) que.push({ w + 1, nr, nc });
					dup[nr][nc] = true;
				}
			}
			else {
				while (0 <= nc + dir8[1][i] && nc + dir8[1][i] < C) {
					nc += dir8[1][i];
					if (board[nr][nc] == '#') break;
					if (!dup[nr][nc]) que.push({ w + 1, nr, nc });
					dup[nr][nc] = true;
				}
			}
		}
	}
}