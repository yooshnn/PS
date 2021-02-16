#include <bits/stdc++.h>
using namespace std;
#define sad cout.flush(), system("pause")
typedef long long ll;
typedef pair<int, int> pii;

const int INF = 128;
enum { DRAWRIGHT, DRAWUP, DRAWLEFT, DRAWDOWN };

struct Graph {
   int R, C, res, dist = INF;
   char puz[5*66][5*66];
   int board[66][66];
   int dup[66][66];
   int par[66][66];
   int par_[66][66];

   Graph (int r, int c) {
      R = r, C = c;
      res = 0;
      fill(&dup[0][0], &dup[0][0] + 66*66, -1);
      fill(&par[0][0], &par[0][0] + 66*66, -1);
      fill(&par_[0][0], &par_[0][0] + 66*66, -1);
   }

   void solve() {

      cin.ignore();
      for (int r = 1; r <= 4*R+1; ++r) {
         string t; getline(cin, t);
         for (int c = 1; c <= 4*C+1; ++c) {
            puz[r][c] = t[c-1];
         }
      }

      for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
         if (puz[4*r-1][4*c-1] == ' ') board[r][c] = 0;
         else board[r][c] = (puz[4*r-1][4*c] == ' ' ? 2 : 1);

         for (int i = 0; i <= 1; ++i) for (int j = 0; j <= 2; ++j) puz[4*r-i][4*c-j] = ' ';
      }

      dup[1][1] = 0;
      dfs(1, 1, 1);
      dfs(1, 1, 2);

      par_[1][1] = -1;

      if (res != 0) {
         track(R, C, DRAWDOWN);

         for (int r = 1; r <= 4*R+1; ++r) {
            for (int c = 1; c <= 4*C+1; ++c) {
               cout << puz[r][c];
            }
            cout << "\n";
         }
      }

      cout << "Number of solutions: " << res << endl;

   }
   void track(int r, int c, int p) {
      if (board[r][c] == 1) {
         if (par_[r][c] == 0 || par_[r][c] == 2) {
            puz[4*r-1][4*c] = puz[4*r-1][4*c-1] = puz[4*r-1][4*c-2] = '*';
            track(r, c+(par_[r][c]==0 ? 1 : -1), (p==DRAWLEFT ? DRAWLEFT : DRAWRIGHT));
         }
         else if (par_[r][c] == 1 || par_[r][c] == 3) {
            puz[4*r][4*c-1] = puz[4*r-1][4*c-1] = puz[4*r-2][4*c-1] = '*'; 
            track(r+(par_[r][c]==3 ? 1 : -1), c, (p==DRAWUP ? DRAWUP : DRAWDOWN));
         }
         else {
            if (p == DRAWDOWN) puz[4*r][4*c-1] = puz[4*r-1][4*c-1] = puz[4*r-2][4*c-1] = '*';
            else puz[4*r-1][4*c] = puz[4*r-1][4*c-1] = puz[4*r-1][4*c-2] = '*';
         }
      }
      else {
         if (par_[r][c] == 0) {
            if (p == DRAWUP) puz[4*r-2][4*c-1] = puz[4*r-1][4*c-1] = puz[4*r-1][4*c] = '*';
            else puz[4*r][4*c-1] = puz[4*r-1][4*c-1] = puz[4*r-1][4*c] = '*';
            track(r, c+1, DRAWLEFT);
         }
         else if (par_[r][c] == 2) {
            if (p == DRAWUP) puz[4*r-2][4*c-1] = puz[4*r-1][4*c-1] = puz[4*r-1][4*c-2] = '*';
            else puz[4*r][4*c-1] = puz[4*r-1][4*c-1] = puz[4*r-1][4*c-2] = '*';
            track(r, c-1, DRAWRIGHT);
         }
         else if (par_[r][c] == 1) {
            if (p == DRAWLEFT) puz[4*r-1][4*c-2] = puz[4*r-1][4*c-1] = puz[4*r-2][4*c-1] = '*';
            else puz[4*r-1][4*c] = puz[4*r-1][4*c-1] = puz[4*r-2][4*c-1] = '*';
            track(r-1, c, DRAWDOWN);
         }
         else if (par_[r][c] == 3) {
            if (p == DRAWLEFT) puz[4*r-1][4*c-2] = puz[4*r-1][4*c-1] = puz[4*r][4*c-1] = '*';
            else puz[4*r-1][4*c] = puz[4*r-1][4*c-1] = puz[4*r][4*c-1] = '*';
            track(r+1, c, DRAWUP);
         }
         else {
            if (p == DRAWDOWN) puz[4*r][4*c-1] = puz[4*r-1][4*c-1] = puz[4*r-1][4*c-2] = '*';
            else puz[4*r-1][4*c] = puz[4*r-1][4*c-1] = puz[4*r-2][4*c-1] = '*';
         }
      }
   }
   void dfs(int r, int c, int dir) {
      if (r==R && c==C) {
         res += 1;
         if (dup[r][c] < dist) {
            dist = dup[r][c];
            for (int i = 1; i <= R; ++i) for (int j = 1; j <= C; ++j) {
               par_[i][j] = par[i][j];
            }
         }
         dup[r][c] = -1;
         return;
      }

      if (board[r][c] == 1) {
         if (dir == 1) {
            if (board[r+1][c]!=0 && dup[r+1][c]==-1) {
               par[r+1][c] = 1, dup[r+1][c] = dup[r][c] + 1;
               dfs(r+1, c, 1);
            }
            if (board[r-1][c]!=0 && dup[r-1][c]==-1) {
               par[r-1][c] = 3, dup[r-1][c] = dup[r][c] + 1;
               dfs(r-1, c, 1);
            }
         }
         else {
            if (board[r][c+1]!=0 && dup[r][c+1]==-1) {
               par[r][c+1] = 2, dup[r][c+1] = dup[r][c] + 1;
               dfs(r, c+1, 2);
            }
            if (board[r][c-1]!=0 && dup[r][c-1]==-1) {
               par[r][c-1] = 0, dup[r][c-1] = dup[r][c] + 1;
               dfs(r, c-1, 2);
            }
         }
      }
      else {
         if (dir == 1) {
            if (board[r][c+1]!=0 && dup[r][c+1]==-1) {
               par[r][c+1] = 2, dup[r][c+1] = dup[r][c] + 1;
               dfs(r, c+1, 2);
            }
            if (board[r][c-1]!=0 && dup[r][c-1]==-1) {
               par[r][c-1] = 0, dup[r][c-1] = dup[r][c] + 1;
               dfs(r, c-1, 2);
            }
         }
         else {
            if (board[r+1][c]!=0 && dup[r+1][c]==-1) {
               par[r+1][c] = 1, dup[r+1][c] = dup[r][c] + 1;
               dfs(r+1, c, 1);
            }
            if (board[r-1][c]!=0 && dup[r-1][c]==-1) {
               par[r-1][c] = 3, dup[r-1][c] = dup[r][c] + 1;
               dfs(r-1, c, 1);
            }
         }
      }

      dup[r][c] = -1;
   }
};

int main() {
   ios::sync_with_stdio(0), cin.tie(0);

   int TEST; cin >> TEST; while (TEST--) {

      int R, C; cin >> R >> C;
      Graph G(R, C);
      G.solve();

   }

}