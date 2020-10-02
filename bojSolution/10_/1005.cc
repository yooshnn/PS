#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[1001];
queue<int> Q;

int T, N, K, W, a, b;
int indegree[1001], time[1001], result[1001];

void flush() {
	for (int i = 0; i < 501; ++i) {
		adj[i].clear();
	}
	memset(indegree, 0, sizeof(indegree));
	memset(time, 0, sizeof(time));
	memset(result, 0, sizeof(result));
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

	cin >> T;

	while (T--) {
		flush();
		cin >> N >> K;
		for (int i = 1; i <= N; ++i) cin >> time[i];
		for (int i = 1; i <= K; ++i) {
			cin >> a >> b;
			indegree[b]++;
			adj[a].push_back(b);
		}
		cin >> W;
		for (int i = 1; i <= N; ++i) {
			if (indegree[i] == 0) {
				result[i] = time[i];
				Q.push(i);
			}
		}
		while (!Q.empty()) {
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
		cout << result[W] << "\n";
	}

	return 0;
}