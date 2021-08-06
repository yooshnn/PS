#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using ll = long long;

int N, M;

struct Dijkstra {
  using elem = pair<ll, int>;
  const ll INF = 2e18;

  int vol;
  vector<ll> dup;
  vector<vector<elem>> adj;
  vector<int> par;

  Dijkstra(int _vol) {
    vol = _vol + 1;
    dup.resize(vol, INF);
    adj.resize(vol);
    par.resize(vol, -1);
  }

  void connect(int u, int v, ll w) {
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
  }

  void run(int base) {
    priority_queue<elem, vector<elem>, greater<elem>> que;
    que.push({0, base});
    par[base] = -1;
    dup[base] = 0;

    while (!que.empty()) {
      auto [cw, id] = que.top(); que.pop();
      if (dup[id] < cw) continue;

      for (auto [w, nxt] : adj[id]) {
        if (dup[nxt] > cw + w) {
          dup[nxt] = cw + w;
          par[nxt] = id;
          que.push({dup[nxt], nxt});
        }
      }
    }
  }

  void solve() {
    vector<pair<int, int>> res;
    fill(&dup[0], &dup[0]+vol, 0);
    for (int i = 1; i <= N; ++i) {
      int x = i;
      while (!dup[x] && par[x] != -1) {
        res.push_back({x, par[x]});
        dup[x] = true;
        x = par[x];
      }
    }

    cout << res.size() << "\n";
    for (pair<int, int> &i : res) {
      cout << i.first << " " << i.second << "\n";
    }
  }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> M;

  Dijkstra G(N);
  
  for (int i = 0; i < M; ++i) {
    int u, v, w; cin >> u >> v >> w;
    G.connect(u, v, w);
  }
  G.run(1);
  G.solve();


}