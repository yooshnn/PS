#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;

int
  N, E,
  scc[100010];
vector<int> adj[100010], tp[100010];

int getScc(int n) {
  int cnt = 0;
  stack<int> order;
  vector<bool> dup(n, false);

  auto dfs1 = [&](int u, auto &&dfs1) -> void {
    dup[u] = true;
    for (int &v : adj[u]) if (!dup[v]) dfs1(v, dfs1);
    order.push(u);
  };
  auto dfs2 = [&](int u, auto &&dfs2) -> void {
    dup[u] = false;
    scc[u] = cnt;
    for (int &v : tp[u]) if (dup[v]) dfs2(v, dfs2);
  };

  for (int i = 1; i <= n; ++i) {
    if (!dup[i]) dfs1(i, dfs1);
  }
  for (int i; !order.empty(); order.pop()) {
    i = order.top();
    if (dup[i]) dfs2(i, dfs2), cnt++;
  }
  
  return cnt;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int TEST; cin >> TEST; while (TEST--) {
    int N, M; cin >> N >> M;

    for (int i = 0; i <= N; ++i) {
      adj[i].clear();
      tp[i].clear();
    }

    for (int u, v; M--; ) {
      cin >> u >> v;
      adj[u].push_back(v);
      tp[v].push_back(u);
    }

    int num = getScc(N), res = 0;
    vector<bool> hasIndeg(num+1, false);

    for (int i = 1; i <= N; ++i) {
      for (int &nxt : adj[i]) {
        if (scc[i] != scc[nxt]) hasIndeg[scc[nxt]] = true;
      }
    }
    for (int i = 1; i <= num; ++i) {
      if (!hasIndeg[i]) res += 1;
    }

    cout << res << "\n";
  }

  sad;
}