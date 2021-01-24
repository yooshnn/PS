#include <bits/stdc++.h>
using namespace std;
#define sad cout.flush(), system("pause")
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tup;

const int INF = 1e8;
int dir4[2][4]{{0, -1, 0, 1}, {1, 0, -1, 0}};

int R, C;
pii init;
char board[50][50];
int dup[50][50];

inline bool oob(int r, int c) { return (r<0 || c<0 || r>=R || c>=C); }

void bfs() {
   queue<tup> que;
   int ch, nh, cr, cc, nr, nc;
   dup[init.first][init.second] = 0;
   for (que.emplace(0, init.first, init.second); !que.empty(); que.pop()) {
      tie(ch, cr, cc) = que.front();
      for (int i = 0; i < 4; ++i) {
         nr = cr + dir4[0][i], nc = cc + dir4[1][i];
         if (oob(nr, nc)) continue;
         nh = ch;
         if (board[nr][nc] == 'G') nh = ch + 1;
         if (board[nr][nc] == 'P') nh = 0;
         if (nh == 4 || dup[nr][nc] <= nh) continue;
         dup[nr][nc] = nh;
         que.push({nh, nr, nc});
      }
   }
}

int main() {
   ios::sync_with_stdio(0), cin.tie(0);
   
   int TEST; cin >> TEST; for (int test = 1; test <= TEST; ++test) {
      cin >> C >> R;
      for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
         cin >> board[r][c];
         if (board[r][c] == 'S') {
            board[r][c] = '.';
            init = {r, c};
         }
         dup[r][c] = INF;
      }

      bfs();

      int res = 0;
      for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
         if (board[r][c] == 'H' && dup[r][c] != INF) res++;
      }

      cout << "Data Set " << test << ":\n" << res << "\n\n";
   }

}