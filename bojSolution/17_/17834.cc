#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Graph {
	int N;
	vector<vector<int>> adj;
	int dup[50002];

	Graph(int n) {
		N = n + 1;
		adj.resize(N);
	}

	void addEdge(int p, int q) {
		adj[p].push_back(q); adj[q].push_back(p);
	}

	ll calc() {
		ll a = 0, b = 0;
		//for (int i = 1; i < N; ++i) {
		int i = 1;
			for (int j = 1; j < N; ++j) dup[j] = 0;
			dup[i] = 1;

			ll cnt = 0;
			queue<pii> que;

			for (que.push({ i, 2 }); !que.empty(); que.pop()) {
				int cur, col; tie(cur, col) = que.front();
				for (int next : adj[cur]) {
					//cout << "dup[" << next << "] = " << dup[next] << "\n";
					if (dup[next] == 0) {
						dup[next] = col;
						//cout << "set dup[" << next << "] to " << col << "\n";
						que.push({ next, (col == 1 ? 2 : 1) });
					}
					else {
						if (dup[next] != col) return 0;
					}
				}
			}

			for (int i = 1; i < N; ++i) {
				//cout << "col " << i << " : " << dup[i] << "\n";
				if (dup[i] == 2) b++;
				else a++;
			}

		//}
		return 2*a*b;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M; cin >> N >> M;
	Graph G(N);
	for (int i = 0; i < M; ++i) {
		int p, q; cin >> p >> q; G.addEdge(p, q);
	}

	cout << /*"result: " <<*/ G.calc();
}