#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <functional>
#include <algorithm>

using namespace std;

const int INF = 2147483647;

int V, E, K, L;
int u, v, w;

vector< pair<int, int> > vertex[20001];
long int dist[20001];
bool visit[20001];
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > Q;

int dijkstra(int pb, int pe);

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0);

	for (int i = 0; i < 20001; ++i) {
		dist[i] = INF;
	}
	memset(visit, false, sizeof(visit));

	cin >> V >> E; // V: 정점 수 E: 간선 수

	for (int i = 0; i < E; ++i) {
		cin >> u >> v >> w;
		vertex[u].push_back(make_pair(w, v));
		vertex[v].push_back(make_pair(w, u));
	}

	cin >> K >> L; // K, L 방문해야 함 

	long long int res[6];
	res[0] = dijkstra(1, K);
	res[1] = dijkstra(1, L);
	res[2] = dijkstra(K, L);
	res[3] = dijkstra(K, V);
	res[4] = dijkstra(L, V);

	res[5] = min(res[0] + res[2] + res[4], res[1] + res[2] + res[3]);

	if (res[5] >= INF) {
		cout << "-1";
	}
	else {
		cout << res[5];
	}

	return 0;
}

int dijkstra(int pb, int pe) {
	for (int i = 0; i < 20001; ++i) {
		dist[i] = INF;
	}
	memset(visit, false, sizeof(visit));

	dist[pb] = 0;
	Q.push(make_pair(0, pb));
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
	return dist[pe];
}