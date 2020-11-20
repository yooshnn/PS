#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;

struct Dijkstra {
	ll INF = 2147483647;

	ll* minDist;
	int N;
	vector<pii>* edges;

	Dijkstra(int n) {
		N = n;
		minDist = new ll[n];
		edges = new vector<pii>[n];

		for (int i = 0; i < n; ++i) {
			minDist[i] = INF;
		}
	}

	void addEdge(int a, int b, ll w) {
		edges[a].push_back({ w, b });
		edges[b].push_back({ w, a });
	}

	ll query(int base, int goal) {
		priority_queue<pii, vector<pii>, greater<pii>> pque;
		pque.push({ 0, base });
		fill(minDist, minDist + N, INF);
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
		if (minDist[goal] == INF) return -1;
		return minDist[goal];
	}

	void build(int base) {
		priority_queue<pii, vector<pii>, greater<pii>> pque;
		pque.push({ 0, base });
		fill(minDist, minDist + N, INF);
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

	int V, E; cin >> V >> E;
	Dijkstra D(V + 1);

	for (int i = 0; i < E; ++i) {
		int p, q, w; cin >> p >> q >> w;
		D.addEdge(p, q, w);
	}

	int base, salesman[10]; for (int i = 0; i < 10; ++i) cin >> salesman[i];
	cin >> base;

	ll t[10]; fill(t, t + 10, 0);
	ll curv = 0, nextv = 1, history = 0;

	while (1) {
		ll req = D.query(salesman[curv], salesman[nextv]);
		if (req != -1) {
			history += req;
			t[nextv] = history;
			curv = nextv;
			nextv = curv + 1;
		}
		else {
			t[nextv] = -1;
			nextv++;
		}
		if (curv > 9 || nextv > 9) {
			//t[curv] = 2147483647;
			break;
		}
	}
	D.build(base);
	//for (int i = 0; i < 10; ++i) cout << t[i] << " "; cout << "\n";
	vector<ll> res;
	for (int i = 0; i < 10; ++i) {
		ll req = D.ask(salesman[i]);
		if (req == -1) continue;
		if (t[i] >= req) res.push_back(salesman[i]);
	}
	if (!res.empty()) cout << *min_element(res.begin(), res.end());
	else cout << -1;
}