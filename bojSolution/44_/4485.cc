#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#define pii pair<int,int>
#define INF 2147483647
#define NODES 20001
using namespace std;

int N, E, K;
int u, v, w;

vector<pii> node[NODES];
long int dist[NODES];
bool visit[NODES];
priority_queue< pii, vector<pii>, greater<pii> > Q;
int board[126][126];

void flush();
long dijkstra();

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

	int problem = 0;
	while (++problem) {
		cin >> N;
		if (N == 0) break;

		flush();

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> board[i][j];
			}
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (j + 1 < N) node[i * N + j].push_back({ board[i][j + 1], i * N + j + 1 });
				if (j - 1 >= 0) node[i * N + j].push_back({ board[i][j - 1], i * N + j - 1 });
				if (i + 1 < N) node[i * N + j].push_back({ board[i + 1][j], (i + 1) * N + j });
				if (i - 1 >= 0) node[i * N + j].push_back({ board[i - 1][j], (i - 1) * N + j });
			}
		}

		cout << "Problem " << problem << ": " << dijkstra() << "\n";
	}

	return 0;
}

void flush() {
	for (auto& cur : dist) cur = INF;
	for (auto& cur : visit) cur = false;
	for (auto& cur : node) cur.clear();
}

long dijkstra() {
	dist[0] = board[0][0];
	Q.push({ board[0][0], 0 });
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

	return dist[N*N-1];
}