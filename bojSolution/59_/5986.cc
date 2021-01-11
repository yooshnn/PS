#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tup;

int N, res;
char board[100][100][100];
int dir[3][6]{ {0, -1, 0, 1, 0, 0}, {1, 0, -1, 0, 0, 0}, {0, 0, 0, 0, -1, 1} };
bool dup[100][100][100];

inline bool oob(int z, int r, int c) {
   return (r < 0 || c < 0 || z < 0 || r >= N || c >= N || z >= N ? true : false);
}

void bfs(tup init) {
	int cz, cr, cc, nz, nr, nc;
   tie(cz, cr, cc) = init;
	queue<tup> que; dup[cz][cr][cc] = true;
	for (que.push(init); !que.empty(); que.pop()) {
		tie(cz, cr, cc) = que.front();
		for (int i = 0; i < 6; ++i) {
         nz = cz + dir[2][i], nr = cr + dir[0][i], nc = cc + dir[1][i];
         if (oob(nz, nr, nc) || dup[nz][nr][nc] || board[nz][nr][nc] == '.') continue;
         dup[nz][nr][nc] = true;
         que.push({nz, nr, nc});
		}
	}
}

int main() {
   ios::sync_with_stdio(0); cin.tie(0);

   cin >> N; 

   for (int z = 0; z < N; ++z) {
      for (int r = 0; r < N; ++r) {
         for (int c = 0; c < N; ++c) {
            cin >> board[z][r][c];
         }
      }
   }

   for (int z = 0; z < N; ++z) {
      for (int r = 0; r < N; ++r) {
         for (int c = 0; c < N; ++c) {
            if (board[z][r][c] == '*' && !dup[z][r][c]) {
               bfs({z, r, c});
               res += 1;
            }
         }
      }
   }

   cout << res;

}