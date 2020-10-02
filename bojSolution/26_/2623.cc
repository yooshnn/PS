#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[1001];
queue<int> Q;

int N, M, a, b;
int indegree[1001];
int result[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		int mysinger;
		cin >> mysinger;
		cin >> a;
		for (int j = 0; j < mysinger - 1; ++j) {
			int prev = a;
			cin >> a;
			indegree[a]++;
			adj[prev].push_back(a);
		}
	}
	for (int i = 1; i <= N; ++i) { // 들어오는 간선이 없는 (indegree가 0인) 정점을 큐에 모두 넣는다
		if (indegree[i] == 0) {
			Q.push(i);
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (Q.empty()) {
			// 위상정렬이 불가능
			cout << 0;
			return 0;
		}
		int cur = Q.front();
		Q.pop();
		result[i] = cur;
		for (int i = 0; i < adj[cur].size(); ++i) {
			indegree[adj[cur][i]]--;
			if (indegree[adj[cur][i]] == 0) {
				Q.push(adj[cur][i]);
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		cout << result[i] << "\n";
	}

	return 0;
}