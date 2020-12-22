#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct Graph {
	bool twoHop[101];
	vector<int> adj[101];

	Graph() {
		fill(&twoHop[0], &twoHop[0] + 101, false);
	}

	void go(int cur) {
		twoHop[cur] = true;
		for (int next : adj[cur]) twoHop[next] = true;
	}
	int calc(int init) {
		int ret = 0;
		for (int next : adj[init]) go(next);
		twoHop[init] = false;
		for (int i = 1; i <= 100; ++i) ret += twoHop[i];
		return ret;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int TEST; cin >> TEST; while (TEST--) {
		int N, E; cin >> N >> E;
		Graph G;
		char t; string p, q;
		for (int i = 0; i < E; ++i) {
			cin >> t >> p >> t >> q;
			G.adj[stoi(p)].push_back(stoi(q));
			G.adj[stoi(q)].push_back(stoi(p));
		}
		cin >> t >> p;
		cout << "The number of supervillains in 2-hop neighborhood of v"
			<< p << " is " << G.calc(stoi(p)) << "\n";
	}
}