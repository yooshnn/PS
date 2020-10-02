#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#define pii pair<int,int>
using namespace std;

int N, K;
bool visit[100001];

int bfs() {
	priority_queue<pii, vector<pii>, greater<pii>>Q;
	Q.push({ 0, N });
	visit[N] = true;

	while (!Q.empty()) {
		int c = Q.top().second;
		int s = Q.top().first;
		Q.pop();

		if (c == K) {
			return s;
		}
		if (c * 2 <= 100000 && !visit[c * 2]) {
			Q.push({ s, c * 2 });
			visit[c * 2] = true;
		}
		if (c + 1 <= 100000 && !visit[c + 1]) {
			Q.push({ s + 1, c + 1 });
			visit[c + 1] = true;
		}
		if (c - 1 >= 0 && !visit[c - 1]) {
			Q.push({ s + 1, c - 1 });
			visit[c - 1] = true;
		}
	}

}

int main() {
	cin >> N >> K;

	cout << bfs();

	return 0;
}