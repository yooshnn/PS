#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using pii = pair<int, int>;
using tup = tuple<int, int, int>;

int R, C;
int board[2010][2010];
bool dup[2010][2010][5];
int dir4[2][4] = {{0, -1, 0, 1}, {1, 0, -1, 0}};
int res;

bool oob(int r, int c) {
  return (r < 1 || c < 1 || r > R || c > C);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> R >> C;
  queue<tup> que;

  for (int r = 1; r <= R; ++r) {
    for (int c = 1; c <= C; ++c) {
      cin >> board[r][c];
      if (board[r][c] == 9) {
        for (int i = 0; i < 4; ++i) que.push({r, c, i}), dup[r][c][4] = true;
      }
    }
  }

  for (; !que.empty(); que.pop()) {
    auto[ro, co, di] = que.front();

    ro += dir4[0][di], co += dir4[1][di];
    if (oob(ro, co) || dup[ro][co][di]) continue;
    dup[ro][co][di] = true;

    if (board[ro][co] == 1 && (di % 2 == 0)) continue;
    if (board[ro][co] == 2 && (di % 2 == 1)) continue;
    if (board[ro][co] == 3) {
      if (di == 0) di = 1; else if (di == 1) di = 0;
      else if (di == 2) di = 3; else if (di == 3) di = 2;
    }
    if (board[ro][co] == 4) {
      if (di == 0) di = 3; else if (di == 1) di = 2;
      else if (di == 2) di = 1; else if (di == 3) di = 0;
    }

    que.push({ro, co, di});
  }

  for (int r = 1; r <= R; ++r) {
    for (int c = 1; c <= C; ++c) {
      res += dup[r][c][0] || dup[r][c][1] || dup[r][c][2] || dup[r][c][3] || dup[r][c][4];
    }
  }

  cout << res;

}