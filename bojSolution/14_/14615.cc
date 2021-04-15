#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;

struct Graph {
  int cap;
  vector<int> cnt, dup;
  vector<vector<int>> adj;
  vector<vector<int>> adjrev;

  Graph (int N) {
    cap = N+1;
    adj.resize(cap);
    adjrev.resize(cap);
    cnt.resize(cap);
    dup.resize(cap, 0);
  }

  void solve() {
    queue<int> que;
    for (que.push(1); !que.empty(); que.pop()) {
      int cur = que.front();
      for (int &nxt : adj[cur]) {
        if (dup[nxt] != 0) continue;
        dup[nxt] = 1;
        cnt[nxt] += 1;
        que.push(nxt);
      }
    }
    fill(&dup[0], &dup[0]+cap, 0);
    for (que.push(cap-1); !que.empty(); que.pop()) {
      int cur = que.front();
      for (int &nxt : adjrev[cur]) {
        if (dup[nxt] != 0) continue;
        dup[nxt] = 1;
        cnt[nxt] += 1;
        que.push(nxt);
      }
    }
  }

};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n, m, q;
  cin >> n >> m;

  Graph G(n);

  while (m--) {
    int u, v; cin >> u >> v;
    G.adj[u].push_back(v);
    G.adjrev[v].push_back(u);
  }

  G.solve();

  cin >> q;
  while (q--) {
    cin >> n;
    cout << (G.cnt[n]==2 ? "Defend the CTP" : "Destroyed the CTP") << "\n";
  }

}