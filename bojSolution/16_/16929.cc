#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;

int R, C,
  dup[60][60],
  dir4[2][4] = {{0, -1, 0, 1}, {1, 0, -1, 0}};
char board[60][60];

bool oob(int r, int c) { return r < 1 || c < 1 || r > R || c > C; }


bool dfs(int r, int c, int x) {
  bool ret = false;
  dup[r][c] = x;
  for (int i = 0; i < 4; ++i) {
    int nr = r + dir4[0][i], nc = c + dir4[1][i];
    if (oob(nr, nc) || board[r][c] != board[nr][nc]) continue;
    if (dup[nr][nc] > 0 && dup[nr][nc] != x - 1) return true;
    if (dup[nr][nc] <= 0) ret |= dfs(nr, nc, x + 1);
  }
  dup[r][c] = -1;
  return ret;
}

bool solve(int r, int c) {
  if (c == C+1) {
    r += 1;
    c = 1;
    if (r == R+1) return false;
  }
  if (dup[r][c] != -1 && dfs(r, c, 1)) return true;
  return solve(r, c+1);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> R >> C;
  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    cin >> board[r][c];
  }

  cout << (solve(1, 1) ? "Yes" : "No");
}