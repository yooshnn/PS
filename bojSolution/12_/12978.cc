#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

vector<int> adj[100010];

pll solve(int u, int par) {
  ll y = 1, n = 0;

  for (int &nxt : adj[u]) {
    if (nxt == par) continue;
    pll req = solve(nxt, u);
    y += min(req.first, req.second);
    n += req.first;
  }

  return {y, n};
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int N; cin >> N;
  for (int u, v; N > 1; --N) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  pll req = solve(1, -1);
  cout << min(req.first, req.second);

  sad;

}