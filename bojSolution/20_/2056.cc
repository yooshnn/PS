#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000 + 1;

vector<int> adj[MAX];
queue<int> Q;

int N, res;
int indegree[MAX], cost[MAX], result[MAX];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> cost[i];
		int K; cin >> K;
		for (int k = 1; k <= K; ++k) {
			indegree[i]++;
			int p; cin >> p; adj[p].push_back(i);
		}
		if (indegree[i] == 0) {
			Q.push(i);
			result[i] = cost[i];
			res = max(res, result[i]);
		}
	}

	for (int i = 1; i <= N; ++i) {
		int cur = Q.front(); Q.pop();
		for (int a : adj[cur]) {
			result[a] = max(result[a], result[cur] + cost[a]);
			res = max(res, result[a]);
			if (--indegree[a] == 0) Q.push(a);
		}
	}

	cout << res;


	return 0;
}