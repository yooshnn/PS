#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tup;

int R, C;
int board[1000][1000];
bool visit[1000][1000];

int bfs() {
	priority_queue < tup, vector<tup>, greater<tup> > Q;
	if (board[0][0] != -1) Q.push({ board[0][0], 0, 0 });
	visit[0][0] = true;
	while (!Q.empty()) {
		tup cur = Q.top(); Q.pop();
		int cr = get<1>(cur), cc = get<2>(cur), cd = get<0>(cur);
		for (int i = 0; i < 4; ++i) {
			int nr = cr, nc = cc;
			if (i == 0) nr++; else if (i == 1) nr--; else if (i == 2) nc++; else if (i == 3) nc--;
			if (nr < 0 || nc < 0 || nr >= R || nc >= C || visit[nr][nc] == true || board[nr][nc] == -1) continue;
			visit[nr][nc] = true;
			if (nr == R - 1 && nc == C - 1) return cd + board[nr][nc];
			Q.push({ cd + board[nr][nc], nr, nc });
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C;
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			cin >> board[r][c];
		}
	}
	if (R == 1 && C == 1)cout << board[0][0];
	else cout << bfs();

}