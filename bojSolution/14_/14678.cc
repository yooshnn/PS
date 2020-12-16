#include <bits/stdc++.h>
using namespace std;

struct Tree {
	int N;
	int b, w, leaf;
	vector<int> ys;
	vector<vector<int>> adj;

	Tree(int n) {
		N = n + 1;
		ys.resize(N, -1);
		adj.resize(N);
		b = w = leaf = 0;
	}

	void addEdge(int p, int q) {
		adj[p].push_back(q); adj[q].push_back(p);
	}

	void dfs(int id, bool f) {
		ys[id] = f;
		if (adj[id].size() == 1) {
			leaf++;
			if (ys[id] == 0) b++; else w++;
		}
		for (int& next : adj[id]) {
			if (ys[next] == -1) dfs(next, 1 - f);
		}
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int N; cin >> N; Tree T(N);
	for (int i = 0; i < N - 1; ++i) {
		int p, q; cin >> p >> q; T.addEdge(p, q);
	}
	for (int i = 1; i <= N; ++i) {
		if (T.adj[i].size() > 1) {
			T.dfs(i, 0);
			break;
		}
	}
	
	if (N == 1) {
		cout << 1; return 0;
	}
	if (T.leaf == N - 1) {
		cout << N - 2; return 0;
	}
	cout << max(T.b, T.w);
}