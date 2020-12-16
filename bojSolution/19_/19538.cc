#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct Graph {
	int N;
	vector<int> pp, ret, dup;
	vector<set<int>> adj;

	Graph(int n) {
		N = n + 1;
		pp.resize(N);
		dup.resize(N, 0);
		ret.resize(N, -1);
		adj.resize(N);
	}

	void addEdge(int p, vector<int>& Q) {
		for (int& q : Q) adj[p].insert(q), adj[q].insert(p);
		pp[p] += (adj[p].size() + 1) / 2;
	}

	vector<int> solve(vector<int>& Q) {
		//for (int& i : pp) i = (i + 1) / 2;
		queue<pii> que; for (int i : Q) que.push({ i, 0 }), ret[i] = 0, dup[i] = true;
		int cid, cl;
		for (; !que.empty(); que.pop()) {
			tie(cid, cl) = que.front();
			for (int next : adj[cid]) {
				if (!dup[next] && --pp[next] == 0) que.push({ next, cl + 1 }), ret[next] = cl + 1, dup[next] = true;
			}
		}
		return ret;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M;

	cin >> N; Graph G(N);
	for (int i = 1; i <= N; ++i) {
		vector<int> adj; int t;
		while (cin >> t) {
			if (t == 0) break;
			adj.push_back(t);
		}
		if (adj.size() != 0) G.addEdge(i, adj);
	}

	cin >> M; vector<int> init(M);
	for (int& i : init) cin >> i;
	vector<int> res = G.solve(init);
	for (int i = 1; i <= N; ++i) cout << res[i] << " ";

}