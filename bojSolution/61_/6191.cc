#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;

int R, C;
char board[114][78];
pii par[114][78];
bool dup[114][78];

int bfsDir[2][4]{ { 0, -1, 0, 1 }, { 1, 0, -1, 0 } };

void bfs() {
	queue<pii> que;
	for (que.push({ 1, 1 }); !que.empty(); que.pop()) {
		int cr, cc; tie(cr, cc) = que.front();
		if (cr == R && cc == C) {
			vector<pii> res;
			while (1) {
				res.push_back({ cr, cc });
				if (cr == 1 && cc == 1) break;
				tie(cr, cc) = par[cr][cc];
			}
			for (int i = res.size() - 1; i >= 0; --i) cout << res[i].first << " " << res[i].second << "\n";
			return;
		}
		for (int i = 0; i < 4; ++i) {
			int nr = cr + bfsDir[0][i], nc = cc + bfsDir[1][i];
			if (nr == 0 || nc == 0 || nr == R + 1 || nc == C + 1 || dup[nr][nc] || board[nr][nc] == '*') continue;
			par[nr][nc] = { cr, cc };
			dup[nr][nc] = true;
			que.push({ nr, nc });
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R >> C;
	for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) cin >> board[r][c];
	bfs();
}