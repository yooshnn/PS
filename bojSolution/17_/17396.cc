#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pii;
typedef long long ll;

struct Dijkstra {
	ll INF = 9223372036854775807;

	ll* minDist;
	vector<pii>* edges;

	Dijkstra(int n) {
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

	void build(int base) {
		priority_queue<pii, vector<pii>, greater<pii>> pque;
		pque.push({ 0, base });
		minDist[base] = 0;

		ll cw, nw;
		int cn, nn;
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

	ll ask(int N) {
		return (minDist[N - 1] == INF ? -1 : minDist[N - 1]);
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M; cin >> N >> M;
	Dijkstra D(N);

	bool visible[100000];
	for (int i = 0; i < N; ++i) {
		visible[i] = false;
		cin >> visible[i];
	}

	for (int i = 0; i < M; ++i) {
		int a, b; ll t; cin >> a >> b >> t;
		if (visible[a] && a != N - 1 || visible[b] && b != N - 1) continue;
		D.addEdge(a, b, t);
	} D.build(0);

	cout << D.ask(N);
}