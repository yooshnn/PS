#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;

int R, C, K;
int board[110][110];
bool dup[110][110];
int dir4[2][4] {{0, -1, 0, 1}, {1, 0, -1, 0}};

bool oob(int r, int c) {
  return (r < 0 || c < 0 || r >= R || c >= C);
}

int bfs(int ir, int ic) {
  int ret = 0;
  queue<pii> que;
  for (que.push({ir, ic}); !que.empty(); que.pop()) {
    auto [cr, cc] = que.front();
    ret += 1;
    for (int i = 0; i < 4; ++i) {
      int nr = cr + dir4[0][i], nc = cc + dir4[1][i];
      if (oob(nr, nc) || dup[nr][nc] || board[nr][nc] == 1) continue;
      dup[nr][nc] = true;
      que.push({nr, nc});
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> R >> C >> K;
  for (int i = 0, c0, r0, c1, r1; i < K; ++i) {
    cin >> c0 >> r0 >> c1 >> r1;
    for (int r = r0; r < r1; ++r) for (int c = c0; c < c1; ++c) board[r][c] = 1;
  }

  vector<int> res;
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      if (dup[r][c] || board[r][c] == 1) continue;
      dup[r][c] = true;
      res.push_back(bfs(r, c));
    }
  }
  sort(res.begin(), res.end());

  cout << res.size() << "\n";
  for (int i : res) cout << i << " ";

}