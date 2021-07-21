#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using ll = long long;

int N, M, spd;
/*
  N: # of belts
  M: corridor
  spd: spd unit time per block
*/

struct Dijkstra {
  using elem = pair<ll, int>;
  const ll INF = 2e18;

  int vol;
  vector<ll> dup;
  vector<vector<elem>> adj;

  Dijkstra(int _vol) {
    vol = _vol + 1;
    dup.resize(vol, INF);
    adj.resize(vol);
  }

  void connect(int u, int v, ll w) {
    adj[u].push_back({w, v});
  }

  void run(int base) {
    priority_queue<elem, vector<elem>, greater<elem>> que;
    que.push({0, base});
    dup[base] = 0;

    while (!que.empty()) {
      auto [cw, id] = que.top(); que.pop();
      if (dup[id] < cw) continue;

      for (auto [w, nxt] : adj[id]) {
        if (dup[nxt] > cw + w) {
          dup[nxt] = cw + w;
          que.push({dup[nxt], nxt});
        }
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> M >> spd;
  
  Dijkstra G(M+1);

  for (int i = 0; i < M; ++i) {
    G.connect(i, i+1, spd);
    if (i+1 != M) G.connect(i+1, i, spd);
  }
  for (int i = 0, u, v, w; i < N; ++i) {
    cin >> u >> v >> w;
    G.connect(u, v, w);
  }

  G.run(0);
  cout << G.dup[M];
  
}