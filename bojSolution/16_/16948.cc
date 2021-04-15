#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using tup = tuple<int, int, int>;

int N, dup[210][210];
bool oob(int r, int c) { return (r < 0 || c < 0 || r >= N || c >= N); }

int dir6[2][6] {
  {-2, -2, 0, 0, 2, 2}, {-1, 1, -2, 2, -1, 1}
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  
  int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
  queue<tup> que;
  for (que.push({r1, c1, 0}); !que.empty(); que.pop()) {
    auto [cr, cc, t] = que.front();
    if (cr == r2 && cc == c2) {
      return cout << t, 0;
    }
    for (int i = 0; i < 6; ++i) {
      int nr = cr + dir6[0][i], nc = cc + dir6[1][i];
      if (oob(nr, nc) || dup[nr][nc] != 0) continue;
      dup[nr][nc] = t+1;
      que.push({nr, nc, t+1});
    }
  }
  return cout << -1, 0;

}