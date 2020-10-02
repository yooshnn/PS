#include <bits/stdc++.h>
using namespace std;

int root[300001];
int N;

int search(int);
void merge(int, int);

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i <= N; ++i) root[i] = i;
	for (int i = 0; i < N - 2; ++i) {
		int p, q; cin >> p >> q;
		merge(p, q);
	}
	cout << "1 ";
	int tar = search(1);

	for (int i = 2; i <= N; ++i) {
		if (search(i) != tar) {
			cout << i << "\n";
			break;
		}
	}

	return 0;
}

int search(int target) {
	if (target == root[target]) return target;
	root[target] = search(root[target]);
	return root[target];
}
void merge(int a, int b) {
	a = search(a); b = search(b);
	if (a == b) return;
	root[b] = a;
}