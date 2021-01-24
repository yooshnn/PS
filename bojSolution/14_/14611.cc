#include <bits/stdc++.h>
using namespace std;
#define sad cout.flush(), system("pause")
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Dijkstra {
	ll INF = 1e16;

	vector<ll> dist;
	vector<vector<pll>> edges;
	vector<ll> par;

	Dijkstra(int n) {
		dist.resize(n, INF);
		edges.resize(n);
		par.resize(n, -1);
	}
	void addEdge(int a, int b, ll w) {
		edges[a].push_back({ w, b });
	}
	void build(ll base) {
		priority_queue<pll, vector<pll>, greater<pll>> pque;
		pque.push({ 0LL, base });
		dist[base] = 0;

		ll cw, nw; int cn, nn;
		while (!pque.empty()) {
			tie(cw, cn) = pque.top(); pque.pop();
			if (dist[cn] < cw) continue;

			for (pll& cur : edges[cn]) {
				nw = cw + cur.first, nn = cur.second;
				if (dist[nn] > nw) {
					par[nn] = cn;
					dist[nn] = nw;
					pque.push({ nw, nn });
				}
			}
		}
	}
	ll ask(int a) {
		return (dist[a] == INF ? -1 : dist[a]);
	}
};

int R, C;
int board[300][300];
int hashIt(int r, int c) { return r*C + c; }

int dir8[2][8]{ {0, -1, 0, 1, -1, -1, 1, 1}, {1, 0, -1, 0, 1, -1, -1, 1} };
inline bool oob(int r, int c) { return (r<0 || c<0 || r>=R || c>=C); }

int main() {
   ios::sync_with_stdio(0), cin.tie(0);
   
   cin >> R >> C;

   Dijkstra G(R*C+2);

   for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
      cin >> board[r][c];
      if (board[r][c] == -2) board[r][c] = 0;
   }

   for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
      for (int i = 0, nr, nc; i < 8; ++i) {
         nr = r + dir8[0][i], nc = c + dir8[1][i];
         if (oob(nr, nc) || board[r][c] == -1 || board[nr][nc] == -1) continue;
         G.addEdge(hashIt(r, c), hashIt(nr, nc), board[nr][nc]);
      }
   }

   for (int r = 1; r < R; ++r) if (board[r][0] != -1) G.addEdge(hashIt(R, 0), hashIt(r, 0), board[r][0]);
   for (int r = 0; r < R-1; ++r) if (board[r][C-1] != -1) G.addEdge(hashIt(r, C-1), hashIt(R, 1), 0);
   for (int c = 1; c < C; ++c) if (board[0][c] != -1) G.addEdge(hashIt(0, c), hashIt(R, 1), 0);
   for (int c = 0; c < C-1; ++c) if (board[R-1][c] != -1) G.addEdge(hashIt(R, 0), hashIt(R-1, c), board[R-1][c]);

   G.build(hashIt(R, 0));
   cout << G.ask(hashIt(R, 1));
   
}