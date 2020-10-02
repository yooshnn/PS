#include <iostream>
#include <string>
#include <algorithm>
#define INF 1e9
#define NODES 501
using namespace std;

int res;
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
				if (dist[i][k] == 1 && dist[k][j] == 1) {
					dist[i][j] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		bool flag = true;
		for (int j = 1; j <= N; ++j) {
			if (i == j) continue;
			if (dist[i][j] == INF && dist[j][i] == INF)
				flag = false;
		}
		if (flag) res++;
	}
	cout << res;

	return 0;
}