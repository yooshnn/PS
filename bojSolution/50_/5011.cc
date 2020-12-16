#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 2147483647;

int N;
ll dp[1002][1002];
char board[1002][1002];
int dir8[2][8]{ {0, -1, 0, 1, -1, -1, 1, 1}, {1, 0, -1, 0, 1, -1, -1, 1} };
bool dup[1002][1002];

bool bfs() {
	int cr, cc, nr, nc;
	queue<pii> que; dup[1][1] = true;
	for (que.push({ 1, 1 }); !que.empty(); que.pop()) {
		tie(cr, cc) = que.front();
		if (cr == N && cc == N) return true;
		for (int i = 0; i < 4; ++i) {
			nr = cr + dir8[0][i], nc = cc + dir8[1][i];
			if (nr < 1 || nc < 1 || nr > N || nc > N || dup[nr][nc] || board[nr][nc] == '#') continue; dup[nr][nc] = true;
			que.push({ nr, nc });
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int r = 1; r <= N; ++r) for (int c = 1; c <= N; ++c) cin >> board[r][c];

	dp[1][1] = 1;
	for (int r = 1; r <= N; ++r) for (int c = 1 + (r == 1); c <= N; ++c) {
		dp[r][c] = ((dp[r - 1][c] + dp[r][c - 1]) * ll(board[r][c] == '.')) % MOD;
	}

	if (dp[N][N] > 0) cout << dp[N][N];
	else {
		if (bfs()) cout << "THE GAME IS A LIE";
		else cout << "INCONCEIVABLE";
	}

}