#include <iostream>
#include <queue>
using namespace std;

int N, K;
int visit[100001];

int bfs() {
	queue<int>Q;
	Q.push(N);

	while (!Q.empty()) {
		int c = Q.front();
		Q.pop();

		if (c == K) {
			return visit[c];
		}
		if (c + 1 <= 100000 && !visit[c + 1]) {
			Q.push(c + 1);
			visit[c + 1] = visit[c] + 1;
		}
		if (c - 1 >= 0 && !visit[c - 1]) {
			Q.push(c - 1);
			visit[c - 1] = visit[c] + 1;
		}
		if (c * 2 <= 100000 && !visit[c * 2]) {
			Q.push(c * 2);
			visit[c * 2] = visit[c] + 1;
		}
	}

}

int main() {
	cin >> N >> K;

	cout << bfs();

	return 0;
}