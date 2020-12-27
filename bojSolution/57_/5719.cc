#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

struct Dijkstra {
	ll INF = 1e16;

	vector<ll> minDist, res;
	vector<vector<pli>> edges;
	vector<vector<int>> par;
	vector<int> dup;
	vector<set<int>> forbidden;

	Dijkstra(int n) {
		minDist.resize(n, INF);
		res.resize(n, INF);
		edges.resize(n);
		par.resize(n);
		dup.resize(n, false);
		forbidden.resize(n);
	}

	void addEdge(int a, int b, ll w) {
		edges[a].push_back({ w, b });
	}

	void build(int base, int dest) {
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
					par[nn].clear();
					par[nn].push_back(cn);
					minDist[nn] = nw;
					pque.push({ nw, nn });
				}
				else if (minDist[nn] == nw) {
					par[nn].push_back(cn);
				}
			}
		}

		queue<int> que;
		for (que.push(dest); !que.empty(); que.pop()) {
			int cur = que.front();
			for (int& n : par[cur]) {
				forbidden[n].insert(cur);
				if (dup[n]) continue; dup[n] = true;
				que.push(n);
			}
		}
	}

	ll solve(int base, int dest) {
		priority_queue<pli, vector<pli>, greater<pli>> pque;
		pque.push({ 0, base });
		res[base] = 0;

		ll cw, nw; int cn, nn;
		while (!pque.empty()) {
			tie(cw, cn) = pque.top(); pque.pop();
			if (res[cn] < cw) continue;

			for (pli& cur : edges[cn]) {
				nw = cw + cur.first, nn = cur.second;
				if (forbidden[cn].find(nn) != forbidden[cn].end()) continue;
				if (res[nn] > nw) {
					res[nn] = nw;
					pque.push({ nw, nn });
				}
			}
		}

		return (res[dest] == INF ? -1 : res[dest]);
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (1) {
		int V, E, base, dest;
		cin >> V >> E; if (V == 0 && E == 0) return 0;
		cin >> base >> dest;

		Dijkstra D(V);

		for (int i = 0; i < E; ++i) {
			int p, q; ll w; cin >> p >> q >> w;
			D.addEdge(p, q, w);
		} D.build(base, dest);

		cout << D.solve(base, dest) << "\n";

	}
}