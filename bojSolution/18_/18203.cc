#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

struct Dijkstra {
	ll INF = 1e16;

	int cap;
	vector<ll> dist;
	vector<vector<pll>> adj;

	Dijkstra(int N) {
    cap = N+1;
    dist.resize(cap, INF);
		adj.resize(cap);
	}
	void addEdge(int u, int v, ll w) {
		adj[u].push_back({ w, v });
		adj[v].push_back({ w, u });
	}
  void flush() {
    fill(dist.begin(), dist.end(), INF);
  }
	void build(int base) {
		priority_queue<pll, vector<pll>, greater<pll>> que;
    que.push({ 0LL, base });
		dist[base] = 0LL;
		ll cw, nw; int cn, nn;
		while (!que.empty()) {
			tie(cw, cn) = que.top(); que.pop();
			if (dist[cn] < cw) continue;
			for (pll& next : adj[cn]) {
				nw = cw + next.first, nn = next.second;
				if (dist[nn] > nw) {
					dist[nn] = nw;
					que.push({ nw, nn });
				}
			}
		}
	}
	ll ask(int a) {
		return (dist[a] == INF ? -1 : dist[a]);
	}
};

int N, M;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> M;
  
  Dijkstra G(N+10);

  for (int i = 0; i < M; ++i) {
    int a, b, t; cin >> a >> b >> t;
    G.addEdge(a, b, t);
  }

  vector<int> dgb;
  for (int i = 0; i < 7; ++i) {
    int t; cin >> t;
    dgb.push_back(t);
  }

  map<pll, ll> dist;

  G.build(1);
  for (int i : dgb) dist[{1, i}] = dist[{i, 1}] = G.ask(i);

  for (int j : dgb) {
    G.flush();
    G.build(j);
    for (int i : dgb) dist[{i, j}] = dist[{j, i}] = G.ask(i);
  }

  sort(dgb.begin(), dgb.end());

  ll res = 2e12;
  do {
    ll temp = dist[{1, dgb[0]}];
    for (int i = 0; i < 7; ++i) {
      temp += dist[{dgb[i], dgb[i-1]}];
    }
    res = min(res, temp);
  } while (next_permutation(dgb.begin(), dgb.end()));

  cout << res;

}