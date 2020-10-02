#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int N;
vector<vector<int> >book(10001);
bool visit[10001];

int allReachable = 1, shortestPath = 20000;

void bfs() {
	priority_queue<pii, vector<pii>, greater<pii> > Q;
	Q.push({ 1, 1 });
	visit[1] = true;
	while (!Q.empty()) {
		int dist = Q.top().first, page = Q.top().second; Q.pop();

		if (book[page].size() == 0) {
			shortestPath = min(shortestPath, dist);
			continue;
		}
		
		for (int p : book[page]) {
			if (visit[p]) continue;
			allReachable++;
			visit[p] = true;
			Q.push({ dist + 1, p });
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		int M; cin >> M;
		for (int j = 1; j <= M; ++j) {
			int input; cin >> input;
			book[i].push_back(input);
		}
	}
	bfs();

	cout << (allReachable == N ? "Y" : "N") << "\n";
	cout << shortestPath;

	return 0;
}