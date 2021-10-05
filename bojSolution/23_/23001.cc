#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int dir4[2][4] = {{0, -1, 0, 1}, {1, 0, -1, 0}};

int
  R, C,
  board[310][310];

bool oob(int r, int c) { return r<1 || c<1 || r>R || c>C; }

ll solve() {
  ll ret = 0;

  cin >> R >> C;
  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    cin >> board[r][c];
  }

  struct cmp {
    bool operator()(pii &l, pii &r) { return board[l.first][l.second] < board[r.first][r.second]; }
  };
  priority_queue<pii, vector<pii>, cmp> que;
  
  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    bool f = false;
    for (int i = 0; i < 4; ++i) {
      int nr = r+dir4[0][i], nc = c+dir4[1][i];
      if (oob(nr, nc)) continue;
      if (board[r][c] > board[nr][nc]+1) f = true;
    }
    if (f) que.push({r, c});
  }

  while (!que.empty()) {
    auto [r, c] = que.top(); que.pop();

    for (int i = 0; i < 4; ++i) {
      int nr = r+dir4[0][i], nc = c+dir4[1][i];
      if (oob(nr, nc)) continue;

      if (board[r][c] > board[nr][nc]+1) {
        ret += ll(board[r][c] - board[nr][nc] - 1);
        board[nr][nc] = board[r][c]-1;
        que.push({nr, nc});
      }
    }
  }

  return ret;

}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int _TEST; cin >> _TEST; for (int TEST = 1; TEST <= _TEST; ++TEST) {
    cout << "Case #" << TEST << ": " << solve() << "\n";
  }

  sad;
}

