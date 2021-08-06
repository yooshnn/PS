#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, K, res;

bool isApartment[100010], good[100010];
vector<pii> adj[100010];

int dfs(int u, int par) {
  int ret = (isApartment[u] ? 1 : 0);
  
  vector<int> subtree;

  for (auto [w, nxt] : adj[u]) {
    if (nxt == par) continue;

    int req = dfs(nxt, u);
    ret += req;
    subtree.push_back(req);
  }

  sort(subtree.begin(), subtree.end());

  if (subtree.empty()) {} // leaf
  else if (subtree.front() == subtree.back() && subtree.front() == 0) {} // all subtrees empty
  else if (subtree.back() == K) {} // all in one subtree
  else good[u] = true;

  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> K;

  for (int i = 1, u, v, w; i < N; ++i) {
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
  }
  for (int i = 0, u; i < K; ++i) {
    cin >> u;
    good[u] = isApartment[u] = true;
  }

  dfs(1, -1);
  
  int res = 0;
  for (int i = 1; i <= N; ++i) res += (good[i] ? 1 : 0);

  cout << res;

  sad;
  
}