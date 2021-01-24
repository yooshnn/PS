#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
#define sad cout.flush(), system("pause")
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tup;
typedef tuple<int, int, int, int> tup4;

const int INF = 1e8;

int R, C;
pii init, dest;
char board[500][500];
int safe[500][500];
int dup[500][500];

vector<pii> corona;

int dir4[2][4] {{0, -1, 0, 1}, {1, 0, -1, 0}};

inline bool oob(int r, int c) {
   return (r<0 || c<0 || r>=R || c>=C);
}

void coronaPrecomp() {
   queue<tup4> que;
   int ir, ic, cr, cc, nr, nc;
   for (pii& x: corona) {
      safe[x.first][x.second] = 0;
      que.push({x.first, x.second, x.first, x.second});
   }
   for (; !que.empty(); que.pop()) {
      tie(ir, ic, cr, cc) = que.front();
      for (int i = 0, t; i < 4; ++i) {
         nr = cr + dir4[0][i], nc = cc + dir4[1][i];
         t = max(abs(ir - nr), abs(ic - nc));
         if (oob(nr, nc) || safe[nr][nc] <= t) continue;
         safe[nr][nc] = t;
         que.push({ir, ic, nr, nc});
      }
   }
}

int solve() {
   priority_queue<tup> que;
   int cs, ns, cr, cc, nr, nc;
   que.push({safe[init.first][init.second], init.first, init.second});
   while (!que.empty()) {
      tie(cs, cr, cc) = que.top(); que.pop();
      if (cr==dest.first && cc==dest.second) return cs;
      for (int i = 0; i < 4; ++i) {
         nr = cr + dir4[0][i], nc = cc + dir4[1][i];
         if (oob(nr, nc) || board[nr][nc]=='#' || board[nr][nc]=='*') continue;
         ns = min(cs, safe[nr][nc]);
         if (dup[nr][nc] >= ns) continue;
         dup[nr][nc] = ns;
         que.push({ns, nr, nc});
      }
   }
   return -1;
}

int main() {
   ios::sync_with_stdio(0), cin.tie(0);
   
   cin >> R >> C;
   int r, c;

   for (r = 0; r < R; ++r) for (c = 0; c < C; ++c) {
      cin >> board[r][c];
      if (board[r][c] == 'S') init = {r, c};
      if (board[r][c] == 'E') dest = {r, c};
      if (board[r][c] == '*') corona.push_back({r, c});
      safe[r][c] = INF;
   }

   coronaPrecomp();

   int req = solve();
   if (req == INF) cout << "safe";
   else cout << req;
}