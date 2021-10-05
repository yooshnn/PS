#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
char board[2010][2010];
bool ok[2010][2010];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int r = 1; r <= N; ++r) for (int c = 1; c <= N; ++c) {
    cin >> board[r][c];
  }

  bool go;

  for (int r = 1; r <= N; ++r) {
    go = false;
    for (int c = 1; c <= N; ++c) {
      if (board[r][c] == 'O') go = true;
      if (board[r][c] == 'X') go = false;
      if (go) ok[r][c] = true;
    }
    go = false;
    for (int c = N; c >= 1; --c) {
      if (board[r][c] == 'O') go = true;
      if (board[r][c] == 'X') go = false;
      if (go) ok[r][c] = true;
    }
    go = false;
    for (int c = 1; c <= N; ++c) {
      if (board[c][r] == 'O') go = true;
      if (board[c][r] == 'X') go = false;
      if (go) ok[c][r] = true;
    }
    go = false;
    for (int c = N; c >= 1; --c) {
      if (board[c][r] == 'O') go = true;
      if (board[c][r] == 'X') go = false;
      if (go) ok[c][r] = true;
    }
  }

  for (int r = 1; r <= N; ++r) {
    for (int c = 1; c <= N; ++c) {
      if (board[r][c] == '.') cout << (ok[r][c] ? '.' : 'B');
      else cout << board[r][c];
    }
    cout << "\n";
  }


  sad;
}