#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;

const ll INF = 0x3f3f3f3f;
ll dp[500010];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int TEST; cin >> TEST;
  for (int tt = 1; tt <= TEST; ++tt) {
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i < n; ++i) dp[i] = INF;

    ll l = INF, r = INF;
    for (int i = 0, x = n-1; i < n; ++i, --x) {
      if (s[i]=='1') l = 0;
      if (s[x]=='1') r = 0;
      dp[i] = min(dp[i], l);
      dp[x] = min(dp[x], r);
      l++, r++;
    }
    cout << "Case #" << tt << ": " << accumulate(&dp[0], &dp[0]+n, 0LL) << "\n";

  }

  sad;
}
