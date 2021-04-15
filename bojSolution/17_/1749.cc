#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using ll = long long;

int R, C;
ll res = -2e16;
ll board[220][220], psum[220][220];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

  cin >> R >> C;
  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    cin >> board[r][c];
    psum[r][c] = board[r][c] + psum[r-1][c] + psum[r][c-1] - psum[r-1][c-1];
  }

  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    for (int i = r; i <= R; ++i) for (int j = c; j <= C; ++j) {
      res = max(res, psum[i][j] - psum[r-1][j] - psum[i][c-1] + psum[r-1][c-1]);
    }
  }

  cout << res;

}