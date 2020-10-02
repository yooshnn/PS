#include <iostream>
#include <string>
#define INF 2e9
using namespace std;

int root[10001];
int fee[10001];
int N, M, K;
int total;

int search(int);
void merge(int, int);

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i) root[i] = i;
	for (int i = 1; i <= N; ++i) cin >> fee[i];

	for (int i = 1; i <= M; ++i) {
		int u, v;
		cin >> u >> v;
		merge(u, v);
	}

	for (int i = 1; i <= N; ++i) {
		total += (fee[i] != INF ? fee[i] : 0);
	}

	cout << (total <= K ? to_string(total) : "Oh no");

	return 0;
}

int search(int target) {
	if (target == root[target]) return target;
	return root[target] = search(root[target]);
}
void merge(int a, int b) {
	a = search(a); b = search(b);
	if (fee[a] > fee[b]) {
		fee[a] = INF;
		if (a == b) return;
		root[a] = b;
	}
	else {
		fee[b] = INF;
		if (a == b) return;
		root[b] = a;
	}
}