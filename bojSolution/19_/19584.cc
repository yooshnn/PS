#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int N, M;
vector<ll> ypos;
set<ll> pos;
map<ll, ll> add, sub;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> M;

  ypos.resize(N);
  for (ll &i : ypos) cin >> i >> i;

  for (ll i = 0, u, v, c; i < M; ++i) {
    cin >> u >> v >> c;
    --u, --v;
    if (ypos[u] > ypos[v]) swap(u, v);
    add[ypos[u]] += c;
    sub[ypos[v]] += c;
    pos.insert(ypos[u]);
    pos.insert(ypos[v]);
  }

  ll res = 0, cur = 0;
  for (ll i : pos) {
    cur += add[i];
    res = max(res, cur);
    cur -= sub[i];
  }

  cout << res;

}