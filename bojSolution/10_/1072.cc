#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  
  ll X, Y; cin >> X >> Y;
  ll prev = (100*Y)/X, res = 1e12;

  if (X == Y) return cout << -1, 0;

  ll lp = 1, rp = 1e12, mid;
  while (lp <= rp) {
    mid = (lp + rp)/2;
    if (100 * (mid + Y) / (mid + X) != prev) {
      rp = mid - 1;
      res = min(res, mid);
    }
    else lp = mid + 1;
  }

  cout << (res == 1e12 ? -1 : res) << endl;
  
}