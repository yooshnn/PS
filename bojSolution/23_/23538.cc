#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;

ll n, res;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for (ll x = 1, x_; x*x*x*x*x < n; ++x) {
    x_ = x*x*x*x*x;
    for (ll y = 1, y_; x_ + y*y*y*y < n; ++y) {
      y_ = y*y*y*y;
      for (ll z = 1, z_; x_ + y_ + z*z*z < n; ++z) {
        z_ = z*z*z;
        ll lp = 1, rp = 32000, w, t = 0;
        while (lp <= rp) {
          w = (lp+rp)/2;
          if (x_ + y_ + z_ + w*w < n) t = w, lp = w+1;
          else rp = w-1;
        }
        res += t;
      }
    }
  }

  cout << res;
}