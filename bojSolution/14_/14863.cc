#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;

const int INF = 2147483647;

int N, K;
int t[2][110], m[2][110], dp[110][100010];

int solve(int i, int time) {
  if (time<0) return -INF;
  if (i==N+1) return 0;
  if (dp[i][time] != -1) return dp[i][time];

  return dp[i][time] = max({
    (solve(i+1, time-t[0][i]) + m[0][i]),
    (solve(i+1, time-t[1][i]) + m[1][i])
  });
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  memset(dp, -1, sizeof dp);

  cin >> N >> K;
  for (int i = 1; i <= N; ++i) {
    cin >> t[0][i] >> m[0][i] >> t[1][i] >> m[1][i];
  }

  cout << solve(0, K);
  
  sad;
}
