#include <iostream>
#include <queue>
using namespace std;

queue<int> Q;
int n, s, r = 0;
int board[100000];
bool visit[100000];

void bfs(int s) {
	Q.push(s);
	visit[s] = true;
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		if (cur - board[cur] >= 0 && !visit[cur - board[cur]]) { Q.push(cur - board[cur]); visit[cur - board[cur]] = true; }
		if (cur + board[cur] < n && !visit[cur + board[cur]]) { Q.push(cur + board[cur]); visit[cur + board[cur]] = true; }
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> board[i];
	}
	cin >> s;
	bfs(s-1);
	for (int i = 0; i < n; ++i) {
		r += visit[i];
	}
	cout << r;

	return 0;
}