#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#define tup tuple<int,int,int>
#define pii pair<int,int>
using namespace std;

int dp[300][300];

queue<tup> Q;

int T, l;
int r_, c_;
pii knight, goal;

void flush() {
	for (int i = 0; i < 300; ++i) {
		for (int j = 0; j < 300; ++j) {
			dp[i][j] = 0;
		}
	}
}

void bfs(int r, int c, int gr, int gc) {
	Q.push({ r, c, 0 });
	while (!Q.empty()) {
		tup cur = Q.front(); Q.pop();
		int cr = get<0>(cur), cc = get<1>(cur), cm = get<2>(cur);
		int nr = cr, nc = cc;
		for (int i = 0; i < 8; ++i) {
			if (i == 0) { nr = cr + 1; nc = cc + 2; }
			if (i == 1) { nr = cr - 1; nc = cc + 2; }
			if (i == 2) { nr = cr + 1; nc = cc - 2; }
			if (i == 3) { nr = cr - 1; nc = cc - 2; }
			if (i == 4) { nr = cr + 2; nc = cc + 1; }
			if (i == 5) { nr = cr + 2; nc = cc - 1; }
			if (i == 6) { nr = cr - 2; nc = cc + 1; }
			if (i == 7) { nr = cr - 2; nc = cc - 1; }

			if (nr < cr && gr - cr > 8) continue;
			if (nr > cr&& cr - gr > 8) continue;
			if (nc < cc && gc - cc > 8) continue;
			if (nc > cc&& cc - gc > 8) continue;

			if (nr < 0 || nc < 0 || nr >= l || nc >= l || dp[nr][nc] > 0 || (nr == r && nc == c)) continue;
			Q.push({ nr, nc, cm + 1 });
			dp[nr][nc] = cm + 1;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

	cin >> T;
	while (T--) {
		flush();

		cin >> l;

		cin >> r_ >> c_;
		knight = { r_, c_ };

		cin >> r_ >> c_;
		goal = { r_, c_ };

		bfs(knight.first, knight.second, goal.first, goal.second);

		cout << dp[abs(goal.first)][abs(goal.second)] << endl;
	}

	return 0;
}