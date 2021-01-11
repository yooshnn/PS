#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tup;

int R, C, res;
bool dup[32][32];
int dir4[2][4] {{0, -1, 0, 1}, {1, 0, -1, 0}};

struct block {
	bool e, n, w, s;
	block() { e = n = w = s = false; }
	void init(int r, int c) {
		n = (r == 1);
		w = (c == 1);
		s = (r == R);
		e = (c == C);
	}
	bool open(int dir) {
		if (dir == 0) return (e == false);
		if (dir == 1) return (n == false);
		if (dir == 2) return (w == false);
		if (dir == 3) return (s == false);
	}
} board[32][32];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	while (cin >> C >> R) {
		if (R + C == 0) break;

		res = 0;
		for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) board[r][c].init(r, c), dup[r][c] = false;
		
		for (int i = 0; i < R*2-1; ++i) {
			for (int j = 0; j < C-(i&1 ? 0 : 1); ++j) {
				int t; cin >> t; if (t == 1) {
					if (i&1) {
						board[1 + i/2][1 + j].s = true;
						board[1 + i/2+1][1 + j].n = true;
					}
					else {
						board[1 + i/2][1 + j].e = true;
						board[1 + i/2][1 + j+1].w = true;
					}
				}
			}
		}
		queue<tup> que; dup[1][1] = true;
		int cr, cc, t, nr, nc;
		for (que.push({1, 1, 1}); !que.empty(); que.pop()) {
			tie(cr, cc, t) = que.front();
			if (cr == R && cc == C) {
				res = t; break;
			}
			for (int i = 0; i < 4; ++i) {
				if (!board[cr][cc].open(i)) continue;
				nr = cr + dir4[0][i], nc = cc + dir4[1][i];
				if (dup[nr][nc]) continue;
				dup[nr][nc] = true;
				que.push({nr, nc, t+1});
			}	
		}
		cout << res << endl;
	}	

    return_0;
}