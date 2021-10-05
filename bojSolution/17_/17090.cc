#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;
using ll = long long;

const int INF = 1e8;

int
  res = 0,
  R, C,
  dup[510][510];
char
  board[510][510];

int dfs(int r, int c, int k) {
  if (dup[r][c] == -1) return -1;
  if (dup[r][c] == 1) return res += k-1, 1;

  res += k;
  if (r == 1 && board[r][c] == 'U') return dup[r][c] = 1;
  if (c == 1 && board[r][c] == 'L') return dup[r][c] = 1;
  if (r == R && board[r][c] == 'D') return dup[r][c] = 1;
  if (c == C && board[r][c] == 'R') return dup[r][c] = 1;
  res -= k;

  dup[r][c] = -1;
  switch (board[r][c]) {
    case 'R': return dup[r][c] = dfs(r, c+1, k+1);
    case 'L': return dup[r][c] = dfs(r, c-1, k+1);
    case 'U': return dup[r][c] = dfs(r-1, c, k+1);
    case 'D': return dup[r][c] = dfs(r+1, c, k+1);
    default: assert(0);
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> R >> C;
  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    cin >> board[r][c];
  }

  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    dfs(r, c, 1);
  }

  cout << res;
  
  sad;
}