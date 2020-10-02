#include <iostream>
#include <algorithm>
#define INF 1e9
#define NODES 101
using namespace std;

int N, M; // ë…¸ë“œ ê°„ì„  ìˆ˜
int dist[NODES][NODES];
int kb[NODES];
int minimum = INF, res;

int main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			dist[i][j] = (i == j ? 0 : INF);
		}
	}
	for (int i = 1; i <= M; ++i) {
		int u, v;
		cin >> u >> v;
		dist[u][v] = 1;
		dist[v][u] = 1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (dist[i][j] == INF) {
				kb[i] = INF;
				break;
			}
			kb[i] += dist[i][j];
		}
		if (kb[i] < minimum) {
			minimum = kb[i];
			res = i;
		}
	}

	cout << res;

	return 0;
}