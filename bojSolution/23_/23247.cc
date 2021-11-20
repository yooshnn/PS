#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int R, C, res, board[310][310], dp[310][310];

int calc(int r0, int c0, int r1, int c1) {
  return dp[r1][c1] - dp[r1][c0-1] - dp[r0-1][c1] + dp[r0-1][c0-1];
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> R >> C;
  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    cin >> board[r][c];
    dp[r][c] = board[r][c] + dp[r-1][c] + dp[r][c-1] - dp[r-1][c-1];
  }

  for (int y = 1; y <= min(R, 10); ++y) {
    for (int x = 1; x <= min(C, 10) && x*y <= 10; ++x) {
      for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
        if (r+y-1 > R || c+x-1 > C) continue;
        if (calc(r, c, r+y-1, c+x-1) == 10) res += 1;
      }
    }
  }

  cout << res;

  sad;

}
