#include <bits/stdc++.h>
using namespace std;

struct Tree {
	int N;
	vector<int> deg;

	Tree(int n) {
		N = n + 1;
		deg.resize(N);
	}

	void addEdge(int p, int q) {
		deg[p]++; deg[q]++;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int N; cin >> N; Tree T(N);
	for (int i = 0; i < N - 1; ++i) {
		int p, q; cin >> p >> q; T.addEdge(p, q);
	}
	int Q; cin >> Q; while (Q--) {
		int t, k; cin >> t >> k;
		if (t == 2) cout << "yes\n";
		else {
			if (T.deg[k] == 1) cout << "no\n";
			else cout << "yes\n";
		}
	}
}