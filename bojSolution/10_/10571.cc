#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<double, double>;

int N;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int TEST; cin >> TEST; while (TEST--) {
    cin >> N;

    int res = 1;
    vector<pii> v(N);
    vector<int> dp(N, 1);
    dp[0] = 1;

    for (pii &i : v) cin >> i.first >> i.second;

    for (int i = 1; i < N; ++i) {
      for (int j = 0; j < i; ++j) {
        if (v[i].first > v[j].first && v[i].second < v[j].second)
          dp[i] = max(dp[i], dp[j]+1);
      }
      res = max(res, dp[i]);
    }

    cout << res << "\n";
  }
  
  sad;
}
