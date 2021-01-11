#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tup;

int K, N, M;
struct Graph {
	int cap;
	vector<int> pasture;
	vector<vector<int>> adj;

	Graph(int N) {
		cap = N+1;
		pasture.resize(cap, 0);
		adj.resize(cap);
	}

	void addEdge(int u, int v) {
		adj[u].push_back(v);
	}

	int solve(vector<int>& cow) {
		for (int& k : cow) {
			vector<bool> dup(N, false);

			queue<int> que; 
			dup[k] = true; pasture[k] += 1;
			for (que.push(k); !que.empty(); que.pop()) {
				int cur = que.front();
				for (int& next: adj[cur]) {
					if (dup[next]) continue;
					dup[next] = true; pasture[next] += 1;
					que.push(next);
				}
			}
		}

		int ret = 0;
		for (int& p : pasture) if (p == K) ret++;
		return ret;
	}
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> K >> N >> M;

	Graph G(N);

	vector<int> cowInit(K);
	for (int& x : cowInit) cin >> x;

	for (int i = 0, u, v; i < M; ++i) {
		cin >> u >> v;
		G.addEdge(u, v);
	}

	cout << G.solve(cowInit);


    return_0;
}