#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;
using ll = long long;

const int dir[2][4] = {{0, -1, 0, 1}, {1, 0, -1, 0}};

int R, C, K, g, pp, res = -1;
char board[1010][1010];
int dup[1010][1010];

bool oob(int r, int c) { return r<pp || c<1 || r>R || c>C; }

int bfs(int ir, int ic) {
  int ret = 0;
  dup[ir][ic] = g;
  queue<pii> que;
  for (que.push({ir, ic}); !que.empty(); que.pop()) {
    auto [cr, cc] = que.front();
    ret += 1;
    for (int i = 0; i < 4; ++i) {
      int nr = cr + dir[0][i], nc = cc + dir[1][i];
      if (oob(nr, nc) || board[nr][nc] == '#' || dup[nr][nc] == g) continue;
      dup[nr][nc] = g;
      que.push({nr, nc});
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> R >> C >> K;

  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    cin >> board[r][c];
  }

  int lp = 1, rp = R;
  while (lp <= rp) {
    pp = (lp+rp)/2;

    g++;
    int maxVol = 0;
    for (int r = pp; r <= R; ++r) for (int c = 1; c <= C; ++c) {
      if (dup[r][c] != g && board[r][c] != '#') maxVol = max(maxVol, bfs(r, c));
    }

    if (maxVol >= K) {
      lp = pp+1;
      res = max(res, pp);
    }
    else rp = pp-1;
  }

  cout << res;

  sad;

}