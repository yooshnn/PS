#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
#define pii pair<int,int>
#define INF 2147483647
#define NODES 101
using namespace std;

int N, E, M;
int u, v, w;
int res = 0;

vector<pii> node[NODES];
long int dist[NODES];
bool visit[NODES];
int item[NODES];
priority_queue< pii, vector<pii>, greater<pii> > Q;

void flush();
int dijkstra(int);

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

	cin >> N >> M >> E; // N: ë…¸ë“œ ìˆ˜ E: ê°„ì„  ìˆ˜
	//cin >> K; // ì‹œìž‘ ë…¸ë“œ

	for (int i = 1; i <= N; ++i) {
		cin >> item[i];
	}

	for (int i = 0; i < E; ++i) {
		cin >> u >> v >> w;
		node[u].push_back({ w, v });
		node[v].push_back({ w, u });
	}

	for (int i = 1; i <= N; ++i) {
		flush();
		res = max(res, dijkstra(i));
		//cout << res << " ";
	}

	cout << res;

	return 0;
}

void flush() {
	for (auto& cur : dist) cur = INF;
	for (auto& cur : visit) cur = false;
	//for (auto& cur : node) cur.clear();
}

int dijkstra(int K) {
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
				//cout << weight << " ";
				if (weight <= M) Q.push({ weight, address });
			}
		}
	}
	int ret = 0;
	for (int i = 1; i <= N; ++i) {
		if (visit[i]) ret += item[i];
	}
	return ret;
}