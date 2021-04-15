#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;

const int INF = 2e7;

int N, K;
pii arr[100010], dp[100010];

int solve() {
  dp[1] = arr[1];
  for (int i = 2; i <= N; ++i) {
    for (int k = 1; k <= K; ++k) {
      if (i - k == 0) break;
      dp[i].first = min(dp[i].first, dp[i-k].first + arr[i].first);
      dp[i].second = min(dp[i].second, dp[i-k].second + arr[i].second);
    }
    // 2s & 5s are independent: the goal is to minimize any of them
  }
  return min(dp[N].first, dp[N].second);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int TEST; cin >> TEST; while (TEST--) {
    cin >> N >> K;
    for (int i = 1, t; i <= N; ++i) {
      cin >> t;
      arr[i] = {0, 0};
      dp[i] = {INF, INF};
      while (t%2 == 0) ++arr[i].first, t /= 2;
      while (t%5 == 0) ++arr[i].second, t /= 5;
    }
    cout << solve() << "\n";
  }

}