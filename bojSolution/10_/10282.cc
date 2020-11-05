#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct Dijkstra {
	int INF = 2147483647;

	int* minDist;
	vector<pii>* edges;

	Dijkstra(int n) {
		minDist = new int[n];
		edges = new vector<pii>[n];

		for (int i = 0; i < n; ++i) {
			minDist[i] = INF;
		}
	}

	void addEdge(int a, int b, int w) {
		edges[a].push_back({ w, b });
		//edges[b].push_back({ w, a });
	}

	void build(int base) {
		priority_queue<pii, vector<pii>, greater<pii>> pque;
		pque.push({ 0, base });
		minDist[base] = 0;

		int cw, cn, nw, nn;
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

	int ask(int a) {
		return (minDist[a] == INF ? -1 : minDist[a]);
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int TEST; cin >> TEST; while (TEST--) {
		int n, d, c; cin >> n >> d >> c;
		Dijkstra D(n + 1);
		for (int i = 0; i < d; ++i) {
			int a, b, s; cin >> a >> b >> s;
			D.addEdge(b, a, s);
		}
		D.build(c);

		int cnt = 0, mxm = 0;
		for (int i = 1; i <= n; ++i) {
			if (D.ask(i) == -1) continue;
			cnt++; mxm = max(mxm, D.ask(i));
		}

		cout << cnt << " " << mxm << "\n";
	}
}