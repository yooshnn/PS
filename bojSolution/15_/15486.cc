#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;

int N;
int dp[1500010];
int T[1500010], P[1500010];

int solve(int i) {
  if (dp[i] != -1) return dp[i];
  if (i > N) return 0;
  
  if (i + T[i] - 1 > N) return solve(i + 1);
  return dp[i] = max(
    solve(i + 1),
    P[i] + solve(i + T[i])
  );
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> T[i] >> P[i];
    dp[i] = -1;
  }

  cout << solve(1);

}