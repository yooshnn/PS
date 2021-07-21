#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using ll = long long;
using pli = pair<ll, int>;

ll dp[1010];

struct Dijkstra {
	ll INF = 1e16;

	int cap;
	vector<ll> dist;
	vector<vector<pli>> adj;

	Dijkstra(int N) {
    cap = N+1;
    dist.resize(cap, INF);  
		adj.resize(cap);
	}
	void addEdge(int u, int v, ll w) {
		adj[u].push_back({ w, v });
	}
	void build(int base) {
		priority_queue<pli, vector<pli>, greater<pli>> que;
    que.push({ 0LL, base });
		dist[base] = 0LL;
		ll cw, nw; int cn, nn;
		while (!que.empty()) {
			tie(cw, cn) = que.top(); que.pop();
			if (dist[cn] < cw) continue;
			for (pli& next : adj[cn]) {
				nw = cw + next.first, nn = next.second;
				if (dist[nn] > nw) {
					dist[nn] = nw;
					que.push({ nw, nn });
				}
			}
		}
	}
	ll ask(int a) {
		return dist[a];
	}
};

int solve(int i, Dijkstra &D) {
  if (dp[i] != -1) return dp[i];
  if (i == 2) return 1;
  dp[i] = 0;

  for (pli &x : D.adj[i]) {
    if (D.ask(i) <= D.ask(x.second)) continue;
    dp[i] += solve(x.second, D);
  }
  return dp[i];
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  for (int i = 0; i < 1010; ++i) dp[i] = -1;

  int N, M;
  cin >> N >> M;

  Dijkstra D(N);

  for (int i = 0; i < M; ++i) {
    int u, v, w; cin >> u >> v >> w;
    D.addEdge(u, v, w);
    D.addEdge(v, u, w);
  }
  D.build(2); // calc distance from T

  cout << solve(1, D);

}