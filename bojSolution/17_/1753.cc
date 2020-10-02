#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <functional>

using namespace std;

const int INF = 2147483647;

int V, E, K;
int u, v, w;

vector< pair<int, int> > vertex[20001];
long int dist[20001];
bool visit[20001];
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > Q;

void dijkstra();

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0);

	for (int i = 0; i < 20001; ++i) {
		dist[i] = INF;
	}

	cin >> V >> E; // V: 정점 수 E: 간선 수
	cin >> K; // 시작 정점

	for (int i = 0; i < E; ++i) {
		cin >> u >> v >> w;
		vertex[u].push_back(make_pair(w, v));
	}

	dijkstra();

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}

	return 0;
}

void dijkstra() {
	dist[K] = 0;
	Q.push(make_pair(0, K));
	while (!Q.empty()) {
		int cw = Q.top().first, cv = Q.top().second;
		Q.pop();

		if (visit[cv] == true) continue;
		if (dist[cv] < cw) continue;
		visit[cv] = true;

		for (int i = 0; i < vertex[cv].size(); ++i) {
			int there = vertex[cv][i].second, next = cw + vertex[cv][i].first;
			//cout << "next: " << next << "there: " << there << endl;
			if (dist[there] > next) {
				dist[there] = next;
				Q.push(make_pair(next, there));
			}
		}
	}
}