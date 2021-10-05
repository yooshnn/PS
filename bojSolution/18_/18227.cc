#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Segt {
  using T = ll;

  static constexpr T def = 0;
  int cap; vector<T> seg;

  Segt(int c = 0, T d = def) : seg(2*(c+1), d), cap(c+1) {}

  T segfun(T i, T j) { return i + j; }
  void update(int i, T v) {
    for (seg[i += cap] += v; i >>= 1; ) {
      seg[i] = segfun(seg[i<<1], seg[(i<<1)^1]);
    }
  }
  T ask(int l, int r) {
    T r1 = def, r2 = def;
    for (l += cap, r += cap; l <= r; l >>= 1, r >>= 1) {
      if (l&1) r1 = segfun(r1, seg[l++]);
      if (~r&1) r2 = segfun(r2, seg[r--]);
    }
    return segfun(r1, r2);
  }
};

int N, C, Q;
vector<int> adj[200010];
int range[200010][2];
ll depth[200010];

int gid = 1;
void dfs(int u, int par) {
  depth[u] = depth[par] + 1;

  range[u][0] = gid++;
  bool leaf = true;

  for (int &v : adj[u]) {
    if (depth[v]) continue;
    dfs(v, u);
    leaf = false;
  }

  gid -= leaf;
  range[u][1] = gid++;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  
  cin >> N >> C;
  for (int i = 1, u, v; i < N; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(C, C);

  Segt T(gid);

  cin >> Q;
  for (int i, j, x, y; Q--; ) {
    cin >> i >> j;
    x = range[j][0], y = range[j][1];

    if (i == 1) T.update(x, 1);
    else cout << T.ask(x, y) * depth[j] << "\n";
  }

  sad;
}