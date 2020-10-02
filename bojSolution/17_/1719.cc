#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#define pii pair<int,int>
#define INF 2147483647
#define NODES 201
using namespace std;

int N, E, K;
int u, v, w;

vector<pii> node[NODES];
long int dist[NODES];
bool visit[NODES];
int res[NODES];
int resdisp[NODES][NODES];

priority_queue< pii, vector<pii>, greater<pii> > Q;

void flush();
void dijkstra(int);

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	flush();

	cin >> N >> E; // N: ë…¸ë“œ ìˆ˜ E: ê°„ì„  ìˆ˜

	for (int i = 0; i < E; ++i) {
		cin >> u >> v >> w;
		node[u].push_back({ w, v });
		node[v].push_back({ w, u });
	}

	for (int i = 1; i <= N; ++i) {
		flush();
		dijkstra(i);
		for (int j = 1; j <= N; ++j) {
			if (i == j) {
				resdisp[j][i] = INF;
			}
			else resdisp[j][i] = res[j];
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (resdisp[i][j] == INF) {
				cout << "- ";
			}
			else {
				cout << resdisp[i][j] << " ";
			}
		}cout << "\n";
	}

	return 0;
}

void flush() {
	for (auto& cur : dist) cur = INF;
	for (auto& cur : visit) cur = false;
	//for (auto& cur : node) cur.clear();
}

void dijkstra(int K) {
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
				res[address] = cv;
				Q.push({ weight, address });
			}
		}
	}
}