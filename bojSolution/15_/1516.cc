#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[501];
queue<int> Q;

int N, req;
int indegree[501], time[501], result[501];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

	cin >> N;

	for (int i = 1; i <= N; ++i) {
		cin >> time[i]; // 각 건물을 짓는 데 걸리는 시간
		while (true) {
			cin >> req;
			if (req == -1) break;
			indegree[i]++;
			adj[req].push_back(i);
		}
	}
	for (int i = 1; i <= N; ++i) { // 들어오는 간선이 없는 (indegree가 0인) 정점을 큐에 모두 넣는다
		if (indegree[i] == 0) {
			result[i] = time[i];
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
		for (int i = 0; i < adj[cur].size(); ++i) {
			result[adj[cur][i]] = max(result[adj[cur][i]], result[cur] + time[adj[cur][i]]);
			indegree[adj[cur][i]]--;
			if (indegree[adj[cur][i]] == 0) {
				Q.push(adj[cur][i]);
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		cout << result[i] << " ";
	}

	return 0;
}