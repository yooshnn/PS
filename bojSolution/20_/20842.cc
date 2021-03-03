#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;
using tup = tuple<int, int, int, int>;

int R, C, K;
char board[102][102];
int dup[202][102][102];

const int INF = 1e6;
bool oob(int r, int c) { return (r<1 || c<1 || r>R || c>C); }
int dir4[2][4] {{0, -1, 0, 1}, {1, 0, -1, 0}};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
 
  cin >> R >> C >> K;

  fill(&dup[0][0][0], &dup[0][0][0] + 202*102*102, INF);
  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) cin >> board[r][c];

  int nk, nr, nc;
  queue<tup> que;
  dup[0][1][1] = 0;

  for (que.push({0, 1, 1, 0}); !que.empty(); que.pop()) {
    auto [ck, cr, cc, t] = que.front();
    if (cr == R && cc == C) return cout << t, 0;
    t += 1;
    for (int i = 0; i < 4; ++i) {
      nr = cr + dir4[0][i], nc = cc + dir4[1][i];
      nk = ck + (board[nr][nc] == '#');
      if (nk > K) continue;
      if (oob(nr, nc)) continue;
      if (dup[nk][nr][nc] <= t) continue;
      dup[nk][nr][nc] = t;
      que.push({nk, nr, nc, t});
    }
  }
  cout << "nej";

}