#include <bits/stdc++.h>
using namespace std;

bool visit[1000001];
int root[1000001];
int n, m, res;

int search(int);
void merge(int, int);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) root[i] = i;
	while (m--) {
		int p, q;
		cin >> p >> q;
		while (search(p) != search(q)) {
			int next = search(p) + 1;
			merge(q, p);
			p = next;
		}
	}
	for (int i = 1; i <= n; ++i) {
		int tar = search(i);
		if (!visit[tar]) res++;
		visit[tar] = true;
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