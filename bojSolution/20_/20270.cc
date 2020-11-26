#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

char board[210][210];
bool dup[210][210];
int dir[2][6]{ {0, -1, -1, 0, 1, 1}, {2, 1, -1, -2, -1, 1} };

int adventure(pii init) {
	int ret = int(board[init.first][init.second] == 'F');
	queue<pii> que;
	dup[init.first][init.second] = true;
	for (que.push(init); !que.empty(); que.pop()) {
		int cr, cc; tie(cr, cc) = que.front();
		for (int i = 0; i < 6; ++i) {
			int nr = cr + dir[0][i], nc = cc + dir[1][i];
			if (dup[nr][nc] || board[nr][nc] == '.' || board[nr][nc] == 'W') continue;
			dup[nr][nc] = true;
			if (board[nr][nc] == 'F') ret++;
			que.push({ nr, nc });
		}
	}
	return ret;
}

int bfs(int N) {
	int ret = 0;
	queue<pii> que;
	dup[N][N * 2 - 1] = true;
	for (que.push({ N, N * 2 - 1 }); !que.empty(); que.pop()) {
		int cr, cc; tie(cr, cc) = que.front();
		for (int i = 0; i < 6; ++i) {
			int nr = cr + dir[0][i], nc = cc + dir[1][i];
			if (dup[nr][nc] || board[nr][nc] == '.') continue;
			if (board[nr][nc] == 'W') {
				dup[nr][nc] = true;
				que.push({ nr, nc });
			}
			else {
				ret = max(ret, adventure({ nr, nc }));
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int TEST; cin >> TEST; while (TEST--) {
		fill(&board[0][0], &board[0][0] + 210 * 210, '.');
		fill(&dup[0][0], &dup[0][0] + 210 * 210, true);
		int n; cin >> n;
		int a = n - 1;
		for (int r = 1; r <= 2 * n - 1; ++r, --a) {
			for (int c = 0; c < 2 * n - 1 - abs(a); ++c) {
				cin >> board[r][1 + abs(a) + c * 2];
				dup[r][1 + abs(a) + c * 2] = false;
			}
		}
		cout << bfs(n) << "\n";
		/*for (int r = 0; r <= 2 * n; ++r) {
			for (int c = 0; c < 4 * n - 1; ++c) {
				cout << board[r][c];
			} cout << "\n";
		}*/
	}
}