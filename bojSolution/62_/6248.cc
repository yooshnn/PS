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
typedef pair<ll, int> pli;

struct Dijkstra {
	ll INF = 1e16;

	vector<ll> minDist;
	vector<vector<pli>> edges;
	vector<ll> par;

	Dijkstra(int n) {
		minDist.resize(n, INF);
		edges.resize(n);
		par.resize(n, -1);
	}

	void addEdge(int a, int b, ll w) {
		edges[a].push_back({ w, b });
		edges[b].push_back({ w, a });
	}

	void build(int base) {
		priority_queue<pli, vector<pli>, greater<pli>> pque;
		pque.push({ 0, base });
		minDist[base] = 0;

		ll cw, nw; int cn, nn;
		while (!pque.empty()) {
			tie(cw, cn) = pque.top(); pque.pop();
			if (minDist[cn] < cw) continue;

			for (pli& cur : edges[cn]) {
				nw = cw + cur.first, nn = cur.second;
				if (minDist[nn] > nw) {
					par[nn] = cn;
					minDist[nn] = nw;
					pque.push({ nw, nn });
				}
			}
		}

	}

	ll ask() {
		ll ret = 0;
		for (ll& x : minDist) {
			if (x != INF) ret = max(ret, x);
		}
		return 2 * ret;
	}
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	int N, M, X; cin >> N >> M >> X;
	Dijkstra D(N+1);
	for (int i = 0, a, b, t; i < M; ++i) {
		cin >> a >> b >> t;
		D.addEdge(a, b, t);
	} D.build(X);

	cout << D.ask();

    return_0;
}