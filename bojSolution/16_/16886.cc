#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int dp[100010];
vector<pii> nxt[100010];

void prep();
int calc(pii &p);

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  prep();
  for (int i = 3; i <= 100000; ++i) {
    vector<bool> g(500, false);
    for (pii &p : nxt[i]) {
      g[calc(p)] = true;
    }
    for (int j = 0; ; ++j) {
      if (!g[j]) {
        dp[i] = j;
        break;
      }
    }
  }

  int i; cin >> i;
  if (dp[i] == 0) cout << -1;
  else {
    for (pii &p : nxt[i]) {
      if (calc(p) == 0) {
        cout << p.second - p.first + 1;
        break;
      }
    }
  }

  sad;
  
}

void prep() {
  for (ll i = 2; (i * (i + 1)) / 2 <= 100000; ++i) {
    for (ll l = 0, r = i; ; ++l, ++r) {
      ll v = (r * (r + 1)) / 2 - (l * (l + 1)) / 2;
      if (v > 100000) break;
      nxt[v].push_back({l + 1, r});
    }
  }
}
int calc(pii &p) {
  auto [l, r] = p;
  int ret = 0;
  for (int i = l; i <= r; ++i) ret ^= dp[i];
  return ret;
}