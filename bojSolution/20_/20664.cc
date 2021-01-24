#include <bits/stdc++.h>
using namespace std;
#define sad cout.flush(), system("pause")
typedef pair<int, int> pii;

const int INF = 1e8;

int R, C;
char board[2000][2000];
int dup[2000][2000], par[2000][2000];
pii init, dest;

int dir4[2][4] {{0, -1, 0, 1}, {1, 0, -1, 0}};

bool oob(int r, int c) {
   return (r<0 || c<0 || r>=R || c>=C);
}

void solve() {
   deque<pii> que; que.push_back(init);
   int cr, cc, nr, nc, cost;
   while (!que.empty()) {
      tie(cr, cc) = que.front(); que.pop_front();
      if (board[cr][cc]=='x') continue;
      for (int i = 0; i < 4; ++i) {
         nr = cr + dir4[0][i], nc = cc + dir4[1][i];
         if (oob(nr, nc)) continue;
         cost = 1 - ((i==0 && board[cr][cc]=='>') || (i==1 && board[cr][cc]=='^') || (i==2 && board[cr][cc]=='<') || (i==3 && board[cr][cc]=='v'));
         if (board[cr][cc] == 'o') cost = 0;
         if (dup[nr][nc] <= dup[cr][cc] + cost) continue;
         dup[nr][nc] = dup[cr][cc] + cost;
         par[nr][nc] = i;
         if (cost) que.push_back({nr, nc});
         else que.push_front({nr, nc});
      }
   }
}
void track() {
   queue<pii> que;
   int cr, cc;
   for (que.push(dest); !que.empty(); que.pop()) {
      tie(cr, cc) = que.front();
      if (cr==init.first && cc==init.second) {
         board[cr][cc] = 'o';
         break;
      }
      if (par[cr][cc] == 0) {
         board[cr][cc-1] = '>';
         que.push({cr, cc-1});
      }
      if (par[cr][cc] == 1) {
         board[cr+1][cc] = '^';
         que.push({cr+1, cc});
      }
      if (par[cr][cc] == 2) {
         board[cr][cc+1] = '<';
         que.push({cr, cc+1});
      }
      if (par[cr][cc] == 3) {
         board[cr-1][cc] = 'v';
         que.push({cr-1, cc});
      }
   }
}

int main() {
   ios::sync_with_stdio(0), cin.tie(0);

   cin >> R >> C;
   int r, c;
   for (r = 0; r < R; ++r) for (c = 0; c < C; ++c) {
      cin >> board[r][c];
      if (board[r][c] == 'o') init = {r, c};
      if (board[r][c] == 'x') dest = {r, c};
      dup[r][c] = INF;
   }
   dup[init.first][init.second] = 0;

   solve();
   track();

   cout << dup[dest.first][dest.second] << "\n";
   for (r = 0; r < R; ++r) {
      for (c = 0; c < C; ++c) {
         cout << board[r][c];
      } cout << "\n";
   }
}