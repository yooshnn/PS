#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

struct Dijkstra {
	ll INF = 2147483647000;

	vector<ll> minDist;
	vector<pii>* edges;

	Dijkstra(int n) {
		minDist.resize(n, INF);
		edges = new vector<pii>[n];
	}

	void addEdge(int a, int b, ll w) {
		//edges[a].push_back({ w, b });
		edges[b].push_back({ w, a });
	}

	void build(int base) {
		priority_queue<pii, vector<pii>, greater<pii>> pque;
		pque.push({ 0, base });
		minDist[base] = 0;

		ll cw, cn, nw, nn;
		while (!pque.empty()) {
			tie(cw, cn) = pque.top(); pque.pop();
			if (minDist[cn] < cw) continue;

			for (pii& cur : edges[cn]) {
				nw = cw + cur.first, nn = cur.second;
				if (minDist[nn] > nw) {
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

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int V, E, K; cin >> V >> E >> K;
	Dijkstra D(V + 2);

	for (int i = 0; i < E; ++i) {
		int p, q; ll w; cin >> p >> q >> w;
		D.addEdge(p, q, w);
	}
	for (int i = 0; i < K; ++i) {
		int p; cin >> p; D.addEdge(V + 1, p, 0); D.addEdge(p, V + 1, 0);
	}
	D.build(V + 1);

	ll resa = -2, resb;
	for (int i = 1; i <= V + 1; ++i) {
		ll req = D.ask(i);
		if (req > resa) {
			resa = req; resb = i;
		}
	}
	cout << resb << "\n" << resa << "\n";
}