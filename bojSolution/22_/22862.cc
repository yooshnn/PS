#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, k, res, arr[1000010], dp[1000010];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> n >> k;
  
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    arr[i] &= 1;
    dp[i] = dp[i-1] + arr[i];
  }

  int lp = 0, rp = n, mid, t;
  while (lp <= rp) {
    mid = (lp+rp)/2;
    t = 0;
    bool good = false;
    for (int i = 1; !good && i <= n-mid+1; ++i) {
      if (dp[i+mid-1] - dp[i-1] <= k) good = true, t = dp[i+mid-1] - dp[i-1];
    }
    if (good) {
      lp = mid+1;
      res = max(res, mid - t);
    }
    else rp = mid-1;

  }

  cout << res;


  sad;
}
