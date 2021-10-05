#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;

int R, C;
char board[1000][1000];

void solve(int r, int c) {
  if (board[r][c] != '.') return;
  board[r][c] = '#';

  if (board[r-2][c] == '#') board[r-1][c] = '#';
  if (board[r+2][c] == '#') board[r+1][c] = '#';
  if (board[r][c-2] == '#') board[r][c-1] = '#';
  if (board[r][c+2] == '#') board[r][c+1] = '#';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> R >> C;
  for (int r = 1; r <= 3*R; ++r) for (int c = 1; c <= 3*C; ++c) {
    cin >> board[r][c];
  }
  for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
    solve(1+3*r+1, 1+3*c+1);
  }
  for (int r = 1; r <= 3*R; ++r) {
    for (int c = 1; c <= 3*C; ++c) cout << board[r][c];
    cout << "\n";
  }



  sad;
}

