#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
vector<ll> atom;
vector<int> adj[210];

pll solve(int v, int par) {
  ll y = atom[v], n = 0;

  for (int &nxt : adj[v]) {
    if (nxt == par) continue;
    pll req = solve(nxt, v);
    y += req.second;
    n += max(req.first, req.second);
  }

  return {y, n};
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> M;

  atom.resize(N);
  for (ll &i : atom) cin >> i;
  sort(atom.begin(), atom.end());

  for (ll t; M > 0; M--) {
    cin >> t;
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
      if (atom[i] + t == atom[j]) adj[i].push_back(j), adj[j].push_back(i);
    }
  }

  pll req = solve(0, -1);
  cout << max(req.first, req.second);

  sad;
}