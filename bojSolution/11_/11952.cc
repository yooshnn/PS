#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using ll = long long;

int N, M, K, S;
ll p, q;
vector<int> zombie;

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
    adj[v].push_back({w, u});
  }

  void spreadZombie() {
    vector<int> dup_(vol, 0);

    queue<elem> que;
    for (int i : zombie) {
      if (S != 0) que.push({S, i});
      dup_[i] = 2;
    }

    for (; !que.empty(); que.pop()) {
      auto [d, i] = que.front();
      if (d == 0) continue;
      for (auto [_, nxt] : adj[i]) {
        if (dup_[nxt]) continue;
        dup_[nxt] = 1;
        que.push({d-1, nxt});
      }
    }

    for (vector<elem> &v : adj) {
      for (elem &i : v) {
        if (dup_[i.second] == 2) i.second = 0;
        else if (i.second == 1 || i.second == N) i.first = 0;
        else i.first = (dup_[i.second] ? q : p);
      }
    }
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

  cin >> N >> M >> K >> S >> p >> q;

  Dijkstra G(N);
  
  zombie.resize(K);
  for (int &i : zombie) cin >> i;
  for (int i = 0, u, v; i < M; ++i) {
    cin >> u >> v;
    G.connect(u, v, 0);
  }
  G.spreadZombie();
  G.run(1);

  cout << G.dup[N];

}