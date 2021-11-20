#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, S, dp[300030];
vector<pii> pic;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> S; pic.resize(N);
  for (pii &i : pic) cin >> i.first >> i.second;
  pic.push_back({0, 0});
  sort(all(pic));

  for (int i = 1; i <= N; ++i) {
    int p = max({0, int(lower_bound(all(pic), pii(pic[i].first - S + 1, 0), [](pii lhs, pii rhs) -> bool {
      return lhs.first < rhs.first;
    }) - pic.begin()) - 1});
    dp[i] = max(dp[i-1], dp[p] + pic[i].second);
  }

  cout << dp[N];

  
  sad;
}