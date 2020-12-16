#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int R, C, K;
int dir[2][4]{ {0, -1, 0, 1}, {1, 0, -1, 0} };
bool board[100][100], dup[100][100];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R >> C >> K;
	for (int i = 0; i < K; ++i) {
		int p, q; cin >> p >> q; board[p - 1][q - 1] = true;
	}

	int res = 0;
	for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) if (!dup[r][c] && board[r][c]) {
		int cnt = 0;
		queue<pii> que;
		for (que.push({ r, c }); !que.empty(); que.pop()) {
			int cr, cc; tie(cr, cc) = que.front();
			for (int i = 0; i < 4; ++i) {
				int nr = cr + dir[0][i], nc = cc + dir[1][i]; 
				if (nr < 0 || nc < 0 || nr == R || nc == C || dup[nr][nc] || !board[nr][nc]) continue;
				cnt++; dup[nr][nc] = true; que.push({ nr, nc });
			}
		}
		res = max(res, cnt);
	}
	cout << res;
}