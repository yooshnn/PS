#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

vector<int> adj[32001];
priority_queue<int, vector<int>, greater<int> > Q;

int N, M, a, b;
int indegree[1001];
int result[1001];
int time[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		cin >> a >> b; // a에서 b로 가는 간선 (a가 b의 선수과목)
		indegree[b]++;
		adj[a].push_back(b);
	}
	for (int i = 1; i <= N; ++i) { // 들어오는 간선이 없는 (indegree가 0인) 정점을 큐에 모두 넣는다
		if (indegree[i] == 0) {
			result[i] = 1;
			Q.push(i);
		}
		time[i] = 1;
	}
	for (int j = 1; j <= N; ++j) {
		if (Q.empty()) return 0;
		int cur = Q.top();
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