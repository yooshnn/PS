#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;

const int dir4[2][4] = {{0, -1, 0, 1}, {1, 0, -1, 0}};

int
  R, C, res,
  board[22][22];

inline bool oob(int r, int c) { return (r<1 || c<1 || r>R || c>C); }

void dfs(int dep, int ro, int co) {
  if (dep >= res) return;

  for (int i = 0; i < 4; ++i) {
    int nr = ro+dir4[0][i], nc = co+dir4[1][i];
    if (oob(nr, nc) || board[nr][nc]==1) continue;
    while (!oob(nr, nc) && board[nr][nc]==0) nr += dir4[0][i], nc += dir4[1][i];
    if (oob(nr, nc)) continue;
    if (board[nr][nc]==3) { res = min(res, dep); return; }
    board[nr][nc] = 0;
    dfs(dep+1, nr-dir4[0][i], nc-dir4[1][i]);
    board[nr][nc] = 1;
  }

}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  while (cin >> C >> R) {
    if (C==0 && R==0) break;

    int r0, c0;
    for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
      int &ref = board[r][c];
      cin >> ref;
      if (ref == 2) r0 = r, c0 = c, ref = 0;
    }
    res = 11;
    dfs(1, r0, c0);

    cout << (res != 11 ? res : -1) << "\n";

  }
  
  sad;
}
