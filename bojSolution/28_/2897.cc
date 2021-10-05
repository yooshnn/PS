#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;

int R, C, res[6];
char board[60][60];

int solve(int r, int c) {
  string s = "####";
  s[0] = board[r-1][c-1];
  s[1] = board[r-1][c];
  s[2] = board[r][c-1];
  s[3] = board[r][c];

  if (count(all(s), '#') != 0) return 5;
  return count(all(s), 'X');

}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> R >> C;
  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    cin >> board[r][c];
    if (r > 1 && c > 1) res[solve(r, c)] += 1;
  }

  for (int i = 0; i < 5; ++i) cout << res[i] << "\n";

  sad;
}
