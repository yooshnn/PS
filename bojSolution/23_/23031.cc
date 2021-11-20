#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using tup = tuple<int, int, bool>;
struct elem;

const int dir[2][4] = { {0, -1, 0, 1}, {1, 0, -1, 0} };
const int lightdir[2][9] = { {0, 0, -1, -1, -1, 0, 1, 1, 1}, {0, 1, 1, 0, -1, -1, -1, 0, 1} };

int N;
string op;

bool oob(int r, int c) { return (r<1 || c<1 || r>N || c>N); }
int res(bool f) {
	if (f == 0) cout << "Aaaaaah!";
	else cout << "Phew...";
	return 0;
}

struct elem {
	int ro, co, di;
	elem(int _r, int _c, int _d = 3) : ro(_r), co(_c), di(_d) { }
	void go(bool ari) { 
		int nr = ro + dir[0][di], nc = co + dir[1][di];
		if (oob(nr, nc)) {
			if (!ari) di = (di + 2) % 4;
		}
		else {
			ro = nr, co = nc;
		}
	}
};

int light[17][17];
vector<elem> zb;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> N >> op;
	for (int r = 1; r <= N; ++r) for (int c = 1; c <= N; ++c) {
		char t; cin >> t;
		if (t == 'Z') zb.push_back(elem(r, c, 3));
		if (t == 'S') light[r][c] = 1;
	}
	
	elem ari(1, 1, 3);
	for (char c : op) {
		if (c == 'L') ari.di = (ari.di + 1) % 4;
		else if (c == 'R') ari.di = (ari.di + 3) % 4;
		else {
			ari.go(1);
			if (light[ari.ro][ari.co] % 2 == 1) {
				for (int i = 0; i < 9; ++i) {
					light[ari.ro+lightdir[0][i]][ari.co+lightdir[1][i]] += 2;			
				}
			}
		}
		
		if (light[ari.ro][ari.co] == 0) {
			for (elem &x : zb) {
				if (x.ro == ari.ro && x.co == ari.co) return res(0);
			}
		}
		for (elem &x : zb) x.go(0);	
		if (light[ari.ro][ari.co] == 0) {
			for (elem &x : zb) {
				if (x.ro == ari.ro && x.co == ari.co) return res(0);
			}
		}
	}
	return res(1);
	
}