#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, k, p[10010], cnt[10010];

bool check(int m) {
  int f = k, g = 0, ret = 0;
  map<int, int> t;
  for (int i = 1; i <= n; ++i) {
    cnt[p[i]] -= 1;
    if (cnt[p[i]] == 0) f -= 1;
    if (t[p[i]] == 0) g += 1;
    t[p[i]] += 1;

    if (i > m) {
      int j = i - m;
      if (cnt[p[j]] == 0) f += 1;
      cnt[p[j]] += 1;
      t[p[j]] -= 1;
      if (t[p[j]] == 0) g -= 1;
    }

    if (f == k && g == k) ret = true;
  }
  for (int i = n - m + 1; i <= n; ++i) cnt[p[i]] += 1;
  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    cnt[p[i]] += 1;
  }

  int lp = 0, rp = n, m, res = 0x3f3f3f3f;
  while (lp <= rp) {
    m = (lp+rp)/2;
    if (check(m)) rp = m-1, res = min(res, m);
    else lp = m+1;
  }
  
  cout << (res == 0x3f3f3f3f ? 0 : res);

  sad;
}