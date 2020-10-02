#include <iostream>
using namespace std;

int root[1000001];
int N, M;

int search(int);
void merge(int,int);

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i <= N; ++i) root[i] = i;
	while (M--) {
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 0) merge(a, b);
		else cout << (search(a) == search(b) ? "YES" : "NO") << "\n";
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