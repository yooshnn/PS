#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int N;
ll res;
bool dup[5010];
vector<pll> adj[5010];

void solve(ll id, ll dist) {
  dup[id] = true;
  res = max(res, dist);
  for (pll &i : adj[id]) {
    if (!dup[i.second]) solve(i.second, dist + i.first);
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 0; i < N-1; ++i) {
    ll a, b, c; cin >> a >> b >> c;
    adj[a].push_back({c, b});
    adj[b].push_back({c, a});
  }

  solve(1, 0);
  cout << res;

}