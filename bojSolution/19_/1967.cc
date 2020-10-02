#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define pii pair<int,int>
using namespace std;

class Graph {
public:
	int N; // 정점의 수
	vector<vector<pii>> adj; // 인접 리스트
	bool visit[10001] = { false, };
	int diameter = 0, res = 0;

	// 생성자
	Graph() : N(0) {}
	Graph(int n) : N(n) { adj.resize(N); }

	// 간선 추가 함수
	void add_edge(int u, int v, int w) {
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}

	void dfs_flush() {
		memset(visit, false, sizeof(visit));
	}

	// 한 정점에서 제일 먼 정점 찾기
	void dfs(pii v) {
		int id = v.first, weight = v.second;
		if (visit[id]) return;
		visit[id] = true;

		if (diameter < weight) {
			diameter = weight;
			res = id;
		}

		for (pii next : adj[id]) {
			dfs({ next.first, next.second + weight });
		}
	}
};

int N, u, v, w;

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

	cin >> N;
	Graph graph(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		cin >> u >> v >> w;
		graph.add_edge(u, v, w);
	}

	graph.dfs_flush();
	graph.dfs({ 1,0 });
	//cout << graph.res << endl;
	graph.dfs_flush();
	graph.dfs({ graph.res,0 });
	cout << graph.diameter;


	return 0;
}