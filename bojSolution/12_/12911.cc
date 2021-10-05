#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

int N, K;
ll res, dp[11][100010];
vector<int> dv[100010];

ll q, w;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> K;

  for (int i = 1; i <= K; ++i) {
    dp[1][i] = 1;
    for (int j = 2; i*j <= K; ++j) dv[i*j].push_back(i);
  }

  q = K;
  for (int i = 2; i <= N; ++i) {
    for (int j = 1; j <= K; ++j) {
      dp[i][j] = q;
      for (int x : dv[j]) {
        dp[i][j] = (MOD + dp[i][j] - dp[i-1][x]) % MOD;
      }
      w += dp[i][j];
    }
    q = w;
    w = 0;
  }
  
  for (int i = 1; i <= K; ++i) {
    res += dp[N][i];
    res %= MOD;
  }

  cout << res;

  sad;
}

