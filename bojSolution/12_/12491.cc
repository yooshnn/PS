#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int T; cin >> T; for (int TEST = 1; TEST <= T; ++TEST) {
    bool impossible = false;
    int R, C; cin >> R >> C;
    char board[R][C];

    for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) cin >> board[r][c];

    for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
      if (board[r][c] == '#') {
        if (r == R-1 || c == C-1 || board[r+1][c] == '.' || board[r][c+1] == '.' || board[r+1][c+1] == '.') {
          impossible = true;
          break;
        }
        board[r][c] = board[r+1][c+1] = '/';
        board[r+1][c] = board[r][c+1] = '\\';
      }
    }

    cout << "Case #" << TEST << ":\n";
    if (impossible) cout << "Impossible\n";
    else {
      for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) cout << board[r][c];
        cout << '\n';
      }
    }
  }
}