#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll INF = 2e16;

int N;
ll val[200010];
vector<int> adj[200010];

pll solve(int v, int par) {
  ll y = (par == -1 ? -INF : val[v] * val[par]), n = 0;

  ll nsum = 0;
  vector<ll> yv, nv;
  
  for (int nxt : adj[v]) {
    if (nxt == par) continue;

    auto [y_, n_] = solve(nxt, v);
    yv.push_back(y_);
    nv.push_back(n_), nsum += n_;
    y += n_;
  }

  // y: 전부 no에서 끌어와야 함 
  // n: 하나의 yes or no | 나머지 no
  for (int i = 0; i < yv.size(); ++i) {
    n = max(n, nsum - nv[i] + max(nv[i], yv[i]));
  }

  return {y, n};
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 2, u; i <= N; ++i) {
    cin >> u;
    adj[u].push_back(i);
  }
  for (int i = 1; i <= N; ++i) cin >> val[i];

  auto [y_, n_] = solve(1, -1);
  cout << max(y_, n_);

  sad;
  
}