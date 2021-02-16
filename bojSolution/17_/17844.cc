#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define sad std::cout.flush(), system("pause")
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

namespace rbk {
  const ll x = 131, md1 = 1e9+7, md2 = 1e9+9;
  int plen; pll d;

  void init(int n) {
    plen = n;
    d = {1, 1};
    for (int i = 0; i < n; ++i) {
      d.first = (d.first * x) % md1, d.second = (d.second * x) % md2;
    }
  }
  pll hash(string &s, int len = 0, int b = 0) {
    pll ret{0, 0};
    ll &r0 = ret.first, &r1 = ret.second;
    for (int i = 0; i < (len > 0 ? len : plen); ++i) {
      r0 = (r0 * x + s[b+i]) % md1, r1 = (r1 * x + s[b+i]) % md2;
    }
    return {r0, r1};
  }
  bool roll(pll &H, string &s, int p) {
    if (p + plen >= s.size()) return false;
    ll &h0 = H.first, &h1 = H.second;
    h0 = (h0 * x + s[p+plen]) % md1;
    h1 = (h1 * x + s[p+plen]) % md2;
    h0 = (h0 + (md1 - d.first * s[p] % md1) % md1) % md1;
    h1 = (h1 + (md2 - d.second * s[p] % md2) % md2) % md2;
    return true;
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  string s; cin >> s;

  int lp = 1, rp = s.size()/2, len, p, found, res = -1;
  pll H;
  ll H_;

  while (lp <= rp) {
    len = (lp + rp)/2;
    map<ll, int> pool;
    
    rbk::init(len);
    H = rbk::hash(s);
    found = false;
    p = 0;
    do {
      H_ = (1+H.first) * (1+H.second);
      if (pool.find(H_) == pool.end()) pool[H_] = p;
      else if (pool[H_] <= p - len) found = true;
    } while (!found && rbk::roll(H, s, p++));

    if (found) lp = len + 1, res = max(res, len);
    else rp = len - 1;
  }
  
  cout << res;
  
}