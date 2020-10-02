#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[32001];
queue<int> Q;

int N, M, a, b;
int indegree[32001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		indegree[b]++;
		adj[a].push_back(b);
	}
	for (int i = 1; i <= N; ++i) { // 들어오는 간선이 없는 (indegree가 0인) 정점을 큐에 모두 넣는다
		if (indegree[i] == 0) {
			Q.push(i);
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (Q.empty()) {
			// 위상정렬이 불가능
			return 0;
		}
		int cur = Q.front();
		Q.pop();
		cout << cur << " ";
		for (int i = 0; i < adj[cur].size(); ++i) {
			indegree[adj[cur][i]]--;
			if (indegree[adj[cur][i]] == 0) {
				Q.push(adj[cur][i]);
			}
		}
	}

	return 0;
}