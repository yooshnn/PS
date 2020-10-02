#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int T;
int N, M;
bool isvalid;

queue<int> Q;
vector<int> adj[501];
bool con[501][501];
int lastyear[501], indegree[501], result[501];

void flush() {
	while (!Q.empty()) Q.pop();
	for (int i = 0; i < 501; ++i) adj[i].clear();
	for (int i = 0; i < 501; ++i) for (int j = 0; j < 501; ++j) con[i][j] = false;
	memset(lastyear, 0, sizeof(lastyear));
	memset(indegree, 0, sizeof(indegree));
	memset(result, 0, sizeof(result));
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

	cin >> T;
	while (T--) {
		flush();

		cin >> N; // 팀의 수
		for (int i = 1; i <= N; ++i) cin >> lastyear[i];
		for (int i = 1; i < N; ++i) {
			for (int j = i + 1; j <= N; ++j) {
				indegree[lastyear[j]]++;
				adj[lastyear[i]].push_back(lastyear[j]);
				con[lastyear[i]][lastyear[j]] = true;
			}
		}
		cin >> M; // 바뀐 쌍의 수
		for (int i = 1; i <= M; ++i) {
			int a, b;
			cin >> a >> b;
			if (con[a][b]) { // a -> b
				adj[a].erase(remove(adj[a].begin(), adj[a].end(), b), adj[a].end());
				adj[b].push_back(a);
				indegree[b]--;
				indegree[a]++;
			}
			else {
				adj[b].erase(remove(adj[b].begin(), adj[b].end(), a), adj[b].end());
				adj[a].push_back(b);
				indegree[a]--;
				indegree[b]++;
			}
		}
		
		for (int i = 1; i <= N; ++i) { // 들어오는 간선이 없는 (indegree가 0인) 정점을 큐에 모두 넣는다
			if (indegree[i] == 0) {
				Q.push(i);
			}
		}
		isvalid = true;
		for (int i = 1; i <= N; ++i) {
			if (Q.empty()) {
				cout << "IMPOSSIBLE\n";
				isvalid = false;
				break;
			}
			if (Q.size() > 1) {
				cout << "?";
				isvalid = false;
				break;
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
		if (isvalid) {
			for (int i = 1; i <= N; ++i) {
				cout << result[i] << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}