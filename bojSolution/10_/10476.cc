#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;
using ll = long long;

const int INF = 1e8;

int
  N, K,
  dp[210][210][3]; // i번 행에서 j개의 방을 k번 방법으로 닫음 {00, 01, 10}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  while (cin >> N >> K) {
    if (!N) sad;

    fill(&dp[0][0][0], &dp[0][0][0]+210*210*3, -INF);
    dp[0][0][0] = 0;

    for (int i = 1, l, r; i <= N; ++i) {
      cin >> l >> r;

      for (int x = 0; x <= min(i, K); ++x) {
        dp[i][x][0] = l + r + max({
          dp[i-1][x][0],
          dp[i-1][x][1],
          dp[i-1][x][2]
        });
        dp[i][x+1][1] = l + max({
          dp[i-1][x][0],
          dp[i-1][x][1]
        });
        dp[i][x+1][2] = r + max({
          dp[i-1][x][0],
          dp[i-1][x][2]
        });
      }
    }

    cout << max({dp[N][K][0], dp[N][K][1], dp[N][K][2]}) << "\n";
    
  }
  
  sad;
}