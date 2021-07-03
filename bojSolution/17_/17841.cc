#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using ll = long long;

int N;
const string UNIST = "UNIST";
ll pp[6], dp[100010][6];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; ++i) {
    int lp = -1, rp = -1;
    string s; cin >> s;

    for (int j = 0; j < 5; ++j) {
      for (int k = j; k < 5; ++k) {
        if (s[k-j] != UNIST[k]) break;
        if (lp == -1) lp = j+1;
        rp = k+1;
      }
    }
    
    if (lp == -1) {
      for (int j = 1; j <= 5; ++j) dp[i][j] = dp[i-1][j];
    }
    else {
      for (int j = 0; j < lp; ++j) {
        dp[i][j] = dp[i-1][j];
      }
      for (int j = rp + 1; j <= 5; ++j) {
        dp[i][j] = dp[i-1][j];
      }
      for (int j = lp; j <= rp; ++j) {
        dp[i][j] = dp[i-1][j];
        if (lp == 1) dp[i][j] += 1;
        else dp[i][j] += dp[i-1][lp-1];
      }
    }
    for (int j = 1; j <= 5; ++j) dp[i][j] %= 1000000007;

  }

  cout << dp[N][5];

}