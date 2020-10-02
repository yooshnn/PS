#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int R, C, res;
char board[250][250];
bool visit[250][250];

void bfs(int r, int c) {
	queue<pii> Q;
	Q.push({ r, c });
	visit[r][c] = true;
	while (!Q.empty()) {
		int cr, cc; tie(cr, cc) = Q.front(); Q.pop();
		for (int i = 0; i < 8; ++i) {
			int nr = cr, nc = cc;
			if (i == 0 || i == 1 || i == 7) nc++; if (i == 3 || i == 4 || i == 5) nc--;
			if (i == 5 || i == 6 || i == 7) nr++; if (i == 1 || i == 2 || i == 3) nr--;
			if (nr < 0 || nc < 0 || nr >= R || nc >= C || visit[nr][nc] || board[nr][nc] == '0') continue;
			visit[nr][nc] = true;
			Q.push({ nr, nc });
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R >> C;
	for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) cin >> board[r][c];
	for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
		if (visit[r][c] || board[r][c] == '0') continue;
		res++;
		bfs(r, c);
	}

	cout << res;


	return 0;
}