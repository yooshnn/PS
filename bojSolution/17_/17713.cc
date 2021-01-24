#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<ll, ll> pll;

struct Dijkstra {
	ll INF = 1e16;

  	ll cap;
	vector<ll> minDist;
	vector<vector<pll>> edges;
	vector<ll> par;

	Dijkstra(int n) {
      	cap = n+1;
		minDist.resize(cap, INF);
		edges.resize(cap);
		par.resize(cap, -1);
	}
	void addEdge(int a, int b, ll w) {
		edges[a].push_back({ w, b });
	}
	void build(ll base) {
		priority_queue<pll, vector<pll>, greater<pll>> pque;
		pque.push({ 0LL, base });
		minDist[base] = 0;

		ll cw, nw; int cn, nn;
		while (!pque.empty()) {
			tie(cw, cn) = pque.top(); pque.pop();
			if (minDist[cn] < cw) continue;

			for (pll& cur : edges[cn]) {
				nw = cw + cur.first, nn = cur.second;
				if (minDist[nn] > nw) {
					par[nn] = cn;
					minDist[nn] = nw;
					pque.push({ nw, nn });
				}
			}
		}
	}
	ll ask(int a) {
		return (minDist[a] == INF ? -1 : minDist[a]);
	}
};

int R, C;
char board[1000][1000];

int hashIt(int r, int c) {
	return 1 + r*C + c;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> R >> C;

    Dijkstra G(R*C);

    for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) cin >> board[r][c];

	int last;
    // slide <
   	for (int r = 0; r < R; ++r) {
	  	for (int c = 0; c < C; ++c) {
		  	if (board[r][c] == '#') {
				last = c + 1;
				continue;
		   	}
			if (board[r][c] == '.' && board[r][c-1] == '.') G.addEdge(hashIt(r, c), hashIt(r, c-1), 2);
		   	//if (c == last) continue;
		   	G.addEdge(hashIt(r, c), hashIt(r, last), 1);
	   }
	}
    // slide >
   	for (int r = 0; r < R; ++r) {
	   	for (int c = C-1; c >= 0; --c) {
		   	if (board[r][c] == '#') {
			   last = c - 1;
			   continue;
		   	}
			if (board[r][c] == '.' && board[r][c+1] == '.') G.addEdge(hashIt(r, c), hashIt(r, c+1), 2);
		   	//if (c == last) continue;
		   	G.addEdge(hashIt(r, c), hashIt(r, last), 1);
	   	}
   	}
	// slide ^
	for (int c = 0; c < C; ++c) {
	  	for (int r = 0; r < R; ++r) {
		  	if (board[r][c] == '#') {
				last = r + 1;
				continue;
		   	}
			if (board[r][c] == '.' && board[r-1][c] == '.') G.addEdge(hashIt(r, c), hashIt(r-1, c), 2);
		   	//if (c == last) continue;
		   	G.addEdge(hashIt(r, c), hashIt(last, c), 1);
	   }
	}
    // slide v
	for (int c = 0; c < C; ++c) {
	  	for (int r = R-1; r >= 0; --r) {
		  	if (board[r][c] == '#') {
				last = r - 1;
				continue;
		   	}
			if (board[r][c] == '.' && board[r+1][c] == '.') G.addEdge(hashIt(r, c), hashIt(r+1, c), 2);
		   	//if (c == last) continue;
		   	G.addEdge(hashIt(r, c), hashIt(last, c), 1);
	   }
	}

	pll p0, p1; cin >> p0.first >> p0.second >> p1.first >> p1.second;

	G.build(hashIt(p0.first - 1, p0.second - 1));
	cout << G.ask(hashIt(p1.first - 1, p1.second - 1)) << endl;

	return_0;
}