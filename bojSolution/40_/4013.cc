#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;
using ll = long long;

const int MAX = 500010;

int
  N, E, S, P,
  scc[MAX],
  val[MAX];
int dp[MAX], indeg[MAX];
bool dup[MAX];
vector<int> adj[MAX], tp[MAX];


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
    if (dup[i]) cnt++, dfs2(i, dfs2);
  }
  
  return cnt;
}


int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int N, M; cin >> N >> M;

  for (int u, v; M--; ) {
    cin >> u >> v;
    adj[u].push_back(v);
    tp[v].push_back(u);
  }

  int num = getScc(N), res = 0;
  
  for (int i = 1, t; i <= N; ++i) { cin >> t; val[scc[i]] += t; }

  for (int i = 1; i <= num; ++i) adj[i].clear();
  
  set<pii> cache;
  for (int i = 1; i <= N; ++i) {
    for (int j : tp[i]) {
      int x = scc[i], y = scc[j];
      if (x == y || cache.find({x, y}) != cache.end()) continue;
      cache.insert({x, y}), cache.insert({y, x});
      adj[y].push_back(x);
    }
  }

  cin >> S >> P;

  queue<int> que;
  for (que.push(scc[S]); !que.empty(); que.pop()) {
    int u = que.front();
    for (int &v : adj[u]) {
      indeg[v] += 1;
      if (!dup[v]) que.push(v), dup[v] = true;
    }
  }

  dp[scc[S]] = val[scc[S]];
  for (que.push(scc[S]); !que.empty(); que.pop()) {
    int u = que.front();
    for (int &v : adj[u]) {
      assert(u != v);
      dp[v] = max(dp[v], dp[u] + val[v]);
      if (--indeg[v] == 0) que.push(v);
    }
  }

  for (int t; P--; ) {
    cin >> t; t = scc[t];
    res = max(res, dp[t]);
  }
  cout << res;


  sad;
}