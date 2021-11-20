#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;

int n, m, c;
int t[100010];

bool check(int z) {
  int cnt = 1, a = t[0], b = 0;
  for (int i = 1; i < n; ++i) {
    if (t[i] - a > z || i - b + 1 > c) {
      cnt += 1;
      a = t[i];
      b = i;
    }
  }
  return (cnt <= m);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> n >> m >> c;
  for (int i = 0; i < n; ++i) cin >> t[i];
  sort(t, t+n);

  int lp = 0, rp = 1000000000, mid, res;
  while (lp <= rp) {
    mid = (lp + rp)/2;
    if (check(mid)) {
      res = mid;
      rp = mid-1;
    }
    else lp = mid+1;
  }

  cout << res;
  
  sad;
}
