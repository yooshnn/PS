#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Tree {
public:
	int N; // 정점의 수
	vector<int> parent; // 부모 노드
	vector<vector<int>> children; // 자식 노드 리스트

	// 생성자
	Tree() : N(0) {}
	Tree(int n) : N(n) {
		parent.resize(N, -1);
		children.resize(N);
	}

	int get_parent(int u) {
		return parent[u];
	}
};

class Graph {
public:
	int N; // 정점의 수
	vector<vector<int>> adj; // 인접 리스트

	// 생성자
	Graph() : N(0) {}
	Graph(int n) : N(n) { adj.resize(N); }

	// 간선 추가 함수
	void add_edge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// 인접한 정점 번호 정렬
	void sort_list() {
		for (int i = 0; i < N; ++i) {
			sort(adj[i].begin(), adj[i].end());
		}
	}

	// BFS로 트리 만들기
	Tree make_tree(int root) {
		Tree T(N);
		vector<bool> visited(N, false);
		queue<int> Q;

		visited[root] = true;
		Q.push(root);
		while (!Q.empty()) {
			int cur = Q.front();
			Q.pop();
			for (int next : adj[cur]) {
				if (visited[next]) continue;
				visited[next] = true;
				Q.push(next);
				T.parent[next] = cur;
				T.children[cur].push_back(next);
			}
		}
		return T;
	}
};

int N, u, v;

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

	cin >> N;
	Graph graph(N + 1);
	for (int i = 0; i < N-1; ++i) {
		cin >> u >> v;
		graph.add_edge(u, v);
	}
	Tree tree = graph.make_tree(1);

	for (int i = 2; i <= N; ++i) {
		cout << tree.get_parent(i) << "\n";
	}

	return 0;
}