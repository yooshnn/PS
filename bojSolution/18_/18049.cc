#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll dp[100010][3];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int TEST; cin >> TEST; while (TEST--) {
    cin >> N;
    vector<ll> v(N+1, 0);
    for (int i = 1; i <= N; ++i) {
      cin >> v[i];

      dp[i][0] = v[i] + max( dp[i-1][1], dp[i-1][2] + (i <= 2 ? 0LL : min(v[i-1], v[i-2])) );
      dp[i][1] = dp[i-1][0];
      dp[i][2] = dp[i-1][1];
    }

    cout << max({ dp[N][0], dp[N][1], dp[N][2] }) << "\n";
  }
  
  sad;
}
