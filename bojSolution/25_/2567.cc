#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;

int board[110][110];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n; cin >> n;
  while (n--) {
    int rr, cc; cin >> rr >> cc;
    for (int r = 0; r < 10; ++r) for (int c = 0; c < 10; ++c) {
      board[rr+r+1][cc+c+1] = 1;
    }
  }
  int res = 0;
  for (int r = 1; r <= 100; ++r) for (int c = 1; c <= 100; ++c) {
    if (board[r][c] == 0) continue;
    res += 4 - (board[r+1][c] + board[r-1][c] + board[r][c+1] + board[r][c-1]);
  }
  cout << res;
}