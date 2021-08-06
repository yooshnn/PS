#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using ll = long long;

int N, M, K;

struct Dijkstra {
  using elem = tuple<ll, int, int>;
  const ll INF = 2e18;

  int vol;
  vector<ll> dup[21];
  vector<vector<elem>> adj;

  Dijkstra(int _vol) {
    vol = _vol + 1;
    for (vector<ll> &i : dup) i.resize(vol, INF);
    adj.resize(vol);
  }

  void connect(int u, int v, ll w) {
    adj[u].push_back({w, v, 0});
    adj[v].push_back({w, u, 0});
  }

  void run(int base) {
    priority_queue<elem, vector<elem>, greater<elem>> que;
    que.push({0, base, 0}); // cost , node id , used tickets
    dup[0][base] = 0;

    while (!que.empty()) {
      auto [cw, id, t] = que.top(); que.pop();
      if (dup[t][id] < cw) continue;

      for (auto [w, nxt, _] : adj[id]) {
        if (dup[t][nxt] > cw + w) {
          dup[t][nxt] = cw + w;
          que.push({dup[t][nxt], nxt, t});
        }
        if (t < K && dup[t+1][nxt] > cw) {
          dup[t+1][nxt] = cw;
          que.push({dup[t+1][nxt], nxt, t+1});
        }
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> M >> K;

  Dijkstra G(N);
  
  for (int i = 0; i < M; ++i) {
    int u, v, w; cin >> u >> v >> w;
    G.connect(u, v, w);
  }
  G.run(1);

  ll res = 2e18;
  for (int i = 0; i <= K; ++i) {
    res = min(res, G.dup[i][N]);
  }
  cout << res;

}