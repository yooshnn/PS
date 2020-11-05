#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int NODES = 1001, INF = 2147483647;

int N, M, X, Y; // N house, M road, X maxDist, Y myHome
vector<pii> edge[NODES];
int dist[NODES];
bool visit[NODES];

void flush() {
	for (auto& c : dist) c = INF;
}

void dijkstra(int base) {

	flush();
	priority_queue<pii, vector<pii>, greater<pii>> pque;
	pque.push({ 0, base }); dist[base] = 0;
	int cw, cn;

	while (!pque.empty()) {
		tie(cw, cn) = pque.top(); pque.pop();

		if (visit[cn] || dist[cn] < cw) continue;
		visit[cn] = true;

		for (pii& cur : edge[cn]) {
			int nw = cw + cur.first, nn = cur.second;
			if (dist[nn] > nw) {
				dist[nn] = nw;
				pque.push({ nw, nn });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M >> X >> Y;
	for (int i = 0; i < M; ++i) {
		int a, b, c; cin >> a >> b >> c;
		edge[a].push_back({ c, b });
		edge[b].push_back({ c, a });
	}

	dijkstra(Y);

	priority_queue<int, vector<int>, greater<int>> pque;
	for (int i = 0; i < N; ++i) {
		pque.push(dist[i]);
	}

	int res = 0;
	while (!pque.empty()) {
		res++;
		int gotSomewhere = false;
		int todaysX = X;
		while (!pque.empty() && pque.top() * 2 <= todaysX) {
			gotSomewhere = true;
			todaysX -= pque.top() * 2;
			pque.pop();
		}
		if (!gotSomewhere) {
			res = -1; break;
		}
	}
	cout << res;
}
