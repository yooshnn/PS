#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#define pii pair<int,int>
#define INF 2147483647
#define NODES 5001
using namespace std;

int N, E, P;
int u, v, w;

vector<pii> node[NODES];
long int dist[NODES];
bool visit[NODES];
priority_queue< pii, vector<pii>, greater<pii> > Q;

void flush();
int dijkstra(int, int);

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

		flush();

		cin >> N >> E; // N: ë…¸ë“œ ìˆ˜ E: ê°„ì„  ìˆ˜
		cin >> P; // ê±´ìš°ê°€ ìžˆëŠ” ë…¸ë“œ

		for (int i = 0; i < E; ++i) {
			cin >> u >> v >> w;
			node[u].push_back({ w, v });
			node[v].push_back({ w, u });
		}

		int d = dijkstra(1, N);
		flush();
		int e = dijkstra(1, P);
		flush();
		e += dijkstra(P, N);

		cout << (d == e ? "SAVE HIM" : "GOOD BYE");

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