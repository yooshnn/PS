#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;

int R, C, res;
int board[52][52];
int dir4[2][4] {{0, -1, 0, 1}, {1, 0, -1, 0}};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> R >> C;
	for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) cin >> board[r][c];

	queue<pii> que;
	for (que.push({1, 1}); !que.empty(); que.pop()) {
		int M, D, r, c; tie(r, c) = que.front();
		res += board[r][c];
		if (r==R && c==C) break;
		board[r][c] = 0; M = 0, D = -1;
		for (int i = 0; i < 4; ++i) {
			if (board[r+dir4[0][i]][c+dir4[1][i]] > M) {
				M = board[r+dir4[0][i]][c+dir4[1][i]];
				D = i;
			}
		}
		if (D == -1) break;
		else (que.push({r+dir4[0][D], c+dir4[1][D]}));
	}

	cout << res;

    return_0;
}