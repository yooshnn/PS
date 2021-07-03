#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

set<pll> tt, res;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  const ll x = 31, md1 = 1e9+9, md2 = 998244353;
  ll H1, H2, d1 = 1, d2 = 1;

  int N, K; cin >> N >> K;
  string s;

  for (int i = 0; i < K; ++i) d1 = (d1 * x) % md1, d2 = (d2 * x) % md2;

  cin >> s;

  H1 = H2 = 0;
  for (int i = 0; i < N; ++i) {
    H1 = (H1 * x + s[i]) % md1;
    H2 = (H2 * x + s[i]) % md2;
    if (i >= K) {
      H1 = (H1 + (md1 - d1 * s[i - K] % md1) % md1) % md1;
      H2 = (H2 + (md2 - d2 * s[i - K] % md2) % md2) % md2;
    }
    if (i >= K - 1) tt.insert({H1, H2});
  }

  cin >> s;

  H1 = H2 = 0;
  for (int i = 0; i < N; ++i) {
    H1 = (H1 * x + s[i]) % md1;
    H2 = (H2 * x + s[i]) % md2;
    if (i >= K) {
      H1 = (H1 + (md1 - d1 * s[i - K] % md1) % md1) % md1;
      H2 = (H2 + (md2 - d2 * s[i - K] % md2) % md2) % md2;
    }
    if (i >= K - 1 && tt.find({H1, H2}) != tt.end()) res.insert({H1, H2});
  }

  cout << res.size();

}