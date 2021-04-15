#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;

int board[100][100];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n; cin >> n;
  while (n--) {
    int rr, cc; cin >> rr >> cc;
    for (int r = 0; r < 10; ++r) for (int c = 0; c < 10; ++c) {
      board[rr+r][cc+c] = 1;
    }
  }
  int res = 0;
  for (int r = 0; r < 100; ++r) for (int c = 0; c < 100; ++c) {
    res += board[r][c];
  }
  cout << res;
}