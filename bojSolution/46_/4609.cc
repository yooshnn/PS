#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tup;

struct Dijkstra {
	ll INF = 1e16;
	int cap;
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

int h(int r, int c) {
	return 1 + r*(C+1) + c;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	while (cin >> R >> C) {
		if (R + C == 0) break;
		Dijkstra G((R+1) * (C+1));

		ll cost; char flow;
		for (int r = 0; r < R; ++r) {
			for (int c = 0; c < C; ++c) {
				cin >> cost >> flow;
				if (cost == 0) continue; cost = 2520LL / cost;
				if (flow == '>' || flow == '*') G.addEdge(h(r, c), h(r, c+1), cost);
				if (flow == '<' || flow == '*') G.addEdge(h(r, c+1), h(r, c), cost);	
			}
			for (int c = 0; c < C+1; ++c) {
				cin >> cost >> flow;
				if (cost == 0) continue; cost = 2520LL / cost;
				if (flow == 'v' || flow == '*') G.addEdge(h(r, c), h(r+1, c), cost);
				if (flow == '^' || flow == '*') G.addEdge(h(r+1, c), h(r, c), cost);	
			}
		}
		for (int c = 0; c < C; ++c) {
			cin >> cost >> flow;
			if (cost == 0) continue; cost = 2520LL / cost;
			if (flow == '>' || flow == '*') G.addEdge(h(R, c), h(R, c+1), cost);
			if (flow == '<' || flow == '*') G.addEdge(h(R, c+1), h(R, c), cost);	
		}

		G.build(1);
		ll req = G.ask(h(R, C));
		if (req == -1) cout << "Holiday";
		else cout << req << " blips";
		cout << "\n";
	}

    return_0;
}