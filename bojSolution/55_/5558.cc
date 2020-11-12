#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tup;

int R, C, N;

int hp = 1;
pii nezumi;
pii cheese[10];

bool dup[10][1000][1000];
char board[1000][1000];
int bfsDir[2][4]{ {0, -1, 0, 1}, {1, 0, -1, 0} };

int bfs() {
	int ret = 0;
	queue<tup> que;
	for (que.push({ 0, nezumi.first, nezumi.second }); !que.empty(); que.pop()) {
		int cw, cr, cc; tie(cw, cr, cc) = que.front();
		if (cheese[hp].first == cr && cheese[hp].second == cc) {
			ret += cw;
			hp += 1;
			if (hp == N + 1) return ret;
			while (!que.empty()) que.pop();
			que.push({ 0, cr, cc });
			que.push({ 0, cr, cc });
			continue;
		}
		for (int i = 0; i < 4; ++i) {
			int nr = cr + bfsDir[0][i], nc = cc + bfsDir[1][i];
			if (nr < 0 || nc < 0 || nr >= R || nc >= C || board[nr][nc] == 'X' || dup[hp][nr][nc]) continue;
			dup[hp][nr][nc] = true;
			que.push({ cw + 1, nr, nc });
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R >> C >> N;

	for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
		cin >> board[r][c];
		if (board[r][c] == 'S') {
			nezumi = { r, c };
			board[r][c] = '.';
		}
		else if ('1' <= board[r][c] && board[r][c] <= '9') {
			cheese[board[r][c] - '0'] = { r, c };
			board[r][c] = '.';
		}
	}

	cout << bfs();
}