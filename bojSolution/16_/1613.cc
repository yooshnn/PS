#include <iostream>
#include <string>
#include <algorithm>
#define INF 1e9
#define NODES 401
using namespace std;

int N, M; // ë…¸ë“œ ê°„ì„  ìˆ˜
int Q;
int dist[NODES][NODES];

int main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			dist[i][j] = INF;
		}
	}
	for (int i = 1; i <= M; ++i) {
		int u, v;
		cin >> u >> v;
		dist[u][v] = 1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	cin >> Q;
	while (Q--) {
		int p, q, get, rev;
		cin >> p >> q;
		get = dist[p][q], rev = dist[q][p];

		if (get == INF && rev == INF) {
			cout << 0;
		}
		else if (get != INF && rev == INF) {
			cout << -1;
		}
		else {
			cout << 1;
		}
		cout << "\n";
	}

	return 0;
}