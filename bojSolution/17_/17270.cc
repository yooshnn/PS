#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <functional>

using namespace std;

const long long INF = 2147483647;

int V, E, J, S;
int u, v, w;

vector< pair<int, int> > vertex[20001];
long long dist[20001];
bool visit[20001];

long long jh[20001];
long long sh[20001];
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > Q;

void flush();
void dijkstra(int);

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0);

	cin >> V >> E; // V: 정점 수 E: 간선 수
	for (int i = 0; i < E; ++i) {
		cin >> u >> v >> w;
		vertex[u].push_back(make_pair(w, v));
		vertex[v].push_back(make_pair(w, u));
	}
	cin >> J >> S; // 시작 정점

	flush();
	dijkstra(J);
	for (int i = 1; i <= V; ++i) jh[i] = dist[i];

	flush();
	dijkstra(S);
	for (int i = 1; i <= V; ++i) sh[i] = dist[i];

	/*cout << "JH: ";
	for (int i = 1; i <= V; ++i) {
		if (jh[i] != INF) cout << jh[i] << " "; else cout << "INF ";
	}
	cout << "\n";
	cout << "SH: ";
	for (int i = 1; i <= V; ++i) {
		if (sh[i] != INF) cout << sh[i] << " "; else cout << "INF ";
	}
	cout << "\n";*/

	long long mnm = INF;
	long long shmxm = 0;
	bool flag = false;
	bool cnd[20001];
	sh[J] = INF;
	jh[J] = INF;
	sh[S] = INF;
	sh[J] = INF;
	for (int i = 1; i <= V; ++i) {
		mnm = min(mnm, sh[i] + jh[i]);
		cnd[i] = false;
	}
	for (int i = 1; i <= V; ++i) {
		//if (i == J || i == S) continue;
		int shmxmsv = shmxm;
		if (sh[i] + jh[i] == mnm) {
			shmxm = max(shmxm, sh[i]);
		}
		if (sh[i] + jh[i] == mnm && jh[i] != INF && sh[i] != INF && jh[i] <= sh[i]) {
			cnd[i] = true;
		}
		if (i == J || i == S) { cnd[i] = false; }
	}
	for (int i = 1; i <= V; ++i) {
		if (cnd[i] == true) {
			if (shmxm == sh[i]) {
				cout << i;
				return 0;
			}
		}
	}
	cout << "-1";

	return 0;
}

void flush() {
	for (int i = 0; i < 20001; ++i) dist[i] = INF;
	for (int i = 0; i < 20001; ++i) visit[i] = false;
}

void dijkstra(int sp) {
	dist[sp] = 0;
	Q.push(make_pair(0, sp));
	while (!Q.empty()) {
		int cw = Q.top().first, cv = Q.top().second;
		Q.pop();

		if (visit[cv] == true) continue;
		if (dist[cv] < cw) continue;
		visit[cv] = true;

		for (int i = 0; i < vertex[cv].size(); ++i) {
			int there = vertex[cv][i].second, next = cw + vertex[cv][i].first;
			if (dist[there] > next) {
				dist[there] = next;
				Q.push(make_pair(next, there));
			}
		}
	}
}