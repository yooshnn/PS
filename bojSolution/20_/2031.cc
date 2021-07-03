#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using pii = pair<int, int>;

int N, D, K;
vector<int> s;

int pp[1000010];
int dp[1000010][11];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> N >> D >> K;
  s.resize(N);

  for (int &i : s) cin >> i;
  sort(s.begin(), s.end());

  for (int i = 0; i < N; ++i) {
    pp[i] = 1 + i - (upper_bound(s.begin(), s.begin() + i, s[i] - D) - s.begin());
  }

  dp[0][1] = pp[0];
  for (int i = 1; i < N; ++i) {
    dp[i][1] = max(dp[i-1][1], pp[i]);
  }

  for (int p = 2; p <= K; ++p) {
    dp[0][p] = pp[0];
    for (int i = 1; i < N; ++i) {
      if (i - pp[i] < 0) {
        dp[i][p] = dp[i-1][p];
        continue;
      }
      dp[i][p] = max(dp[i - pp[i]][p - 1] + pp[i], dp[i - 1][p]);
    }
  }
  
  /*
  cout << "@ PRECOMP\n";
  for (int j = 0; j < N; ++j) cout << pp[j] << " ";
  cout << endl << endl;
  */

  int res = 0;
  for (int i = 1; i <= 10; ++i) {
    for (int j = 0; j < 1000010; ++j) res = max(res, dp[j][i]);
    // for (int j = 0; j < N; ++j) cout << dp[j][i] << " ";
    // cout << endl;
  }
  cout << res;


}