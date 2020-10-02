#include <iostream>
#include <map>
using namespace std;

map<int,int> m;
int root[1001];
int N, M, res;

int search(int);
void merge(int, int);

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i <= N; ++i) root[i] = i;
	while (M--) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}

	for (int i = 1; i <= N; ++i) {
		int t = search(root[i]);
		if (m[t] == 0) {
			m[t] = 1;
			res++;
		}
	}

	cout << res;

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