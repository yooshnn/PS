#include <iostream>
using namespace std;

int root[201];
int travel[1000];
int N, M;

int search(int);
void merge(int, int);

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i) root[i] = i;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			bool con;
			cin >> con;
			if (j <= i) continue;
			if (con) merge(i, j);
		}
	}
	for (int i = 0; i < M; ++i) {
		cin >> travel[i];
	}
	for (int i = 1; i < M; ++i) {
		if (search(travel[i - 1]) == search(travel[i])) continue;
		else {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

	return 0;
}

int search(int target) {
	if (target == root[target]) return target;
	return root[target] = search(root[target]);
}
void merge(int a, int b) {
	a = search(a); b = search(b);
	if (a == b) return;
	root[b] = a;
}