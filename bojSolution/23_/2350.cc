#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int
  N, M, Q,
  root[1010],
  dup[1010];

vector<pii>
  adj[1010];

void init();
int dsfind(int);
void dsmerge(int, int);

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  init();

  cin >> N >> M >> Q;

  using elem = tuple<int, int, int>;
  priority_queue<elem> pque;

  for (int i = 0, u, v, w; i < M; ++i) {
    cin >> u >> v >> w;
    pque.push({w, u, v});
  }
  while (!pque.empty()) {
    auto [w, u, v] = pque.top();
    pque.pop();
    if (dsfind(u) == dsfind(v)) continue;
    dsmerge(u, v);
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
  }

  for (int u, v; Q--; ) {
    cin >> u >> v;

    queue<pii> que;
    for (que.push({200, u}), dup[u] = Q; !que.empty(); que.pop()) {
      auto [w, c] = que.front();
      if (c == v) {
        cout << w << "\n";
        break;
      }
      for (auto [nw, nc] : adj[c]) {
        if (dup[nc] == Q) continue;
        dup[nc] = Q;
        que.push({min(w, nw), nc});
      }
    }
  }

  sad;
}

void init() {
  for (int i = 1; i <= 1000; ++i) root[i] = i, dup[i] = -1;
}
int dsfind(int tar) {
  if (tar == root[tar]) return tar;
  return root[tar] = dsfind(root[tar]);
}
void dsmerge(int a, int b) {
  a = dsfind(a), b = dsfind(b);
  if (a != b) root[a] = b;
}