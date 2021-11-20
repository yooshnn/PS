#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;

int dir[2][8] = { {-1, -2, -2, -1, 1, 2, 2, 1}, {2, 1, -1, -2, -2, -1, 1, 2} };
bool oob(int r, int c) { return r<1 || c<1 || r>5 || c>5; }

char board[7][7];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int cnt = 0;
  for (int r = 1; r <= 5; ++r) for (int c = 1; c <= 5; ++c) {
    cin >> board[r][c];
    if (board[r][c]=='k') cnt += 1;
  }

  bool valid = true;
  for (int r = 1; r <= 5; ++r) for (int c = 1; c <= 5; ++c) {
    if (board[r][c]=='.') continue;
    for (int i = 0; i < 8; ++i) {
      int nr = r + dir[0][i], nc = c + dir[1][i];
      if (oob(nr, nc) || board[nr][nc]=='.') continue;
      valid = false;
    }
  }

  cout << (cnt==9 && valid ? "valid" : "invalid");
  
  sad;
}