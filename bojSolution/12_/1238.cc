#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
#define pii pair<int,int>
#define INF 2147483647
#define NODES 1001
using namespace std;

int N, E, X;
int u, v, w;

vector<pii> node[NODES];
long int dist[NODES];
bool visit[NODES];
priority_queue< pii, vector<pii>, greater<pii> > Q;

void flush();
int dijkstra(int, int);

int res = 0;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

	cin >> N >> E; // N: ë…¸ë“œ ìˆ˜ E: ê°„ì„  ìˆ˜
	cin >> X; // íŒŒí‹° ìž¥ì†Œ

	for (int i = 0; i < E; ++i) {
		cin >> u >> v >> w;
		node[u].push_back({ w, v });
	}

	for (int i = 1; i <= N; ++i) {
		flush();
		int t = 0;
		t = dijkstra(i, X);
		flush();
		t += dijkstra(X, i);
		res = max(res, t);
	}

	cout << res;

	return 0;
}

void flush() {
	for (auto& cur : dist) cur = INF;
	for (auto& cur : visit) cur = false;
	//for (auto& cur : node) cur.clear();
}

int dijkstra(int K, int G) {
	dist[K] = 0;
	Q.push({ 0, K });
	while (!Q.empty()) {
		int cw = Q.top().first, cv = Q.top().second;
		Q.pop();

		if (visit[cv] == true) continue;
		if (dist[cv] < cw) continue;
		visit[cv] = true;

		for (pii cur : node[cv]) {
			int weight = cw + cur.first, address = cur.second;
			if (dist[address] > weight) {
				dist[address] = weight;
				Q.push({ weight, address });
			}
		}
	}

	return dist[G];
}