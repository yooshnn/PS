#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef tuple<bool, bool, bool, bool> fed;
typedef tuple<int, int, int, fed> tup; // cost, r, c, fed?

const int INF = 2147483647;
int res = INF;

int N, M;
int cost[3]; // Knight, Bishop, Rook
pii init;
int food[50][50];
int dup[50][50][2][2][2][2]; // r, c, A, B, C, D

int dirK[2][8] {{-1, -2, -2, -1, 1, 2, 2, 1}, {2, 1, -1, -2, -2, -1, 1, 2}};

inline bool oob(int r, int c) {
   if (r < 0 || c < 0 || r >= N || c >= N) return true;
   return false;
}

void bfs() {
   queue<tup> que;
   dup[init.first][init.second][0][0][0][0] = 0;
   que.push({0, init.first, init.second, {false, false, false, false}});
   while (!que.empty()) {
      int Cost, cr, cc; fed F;
      tie(Cost, cr, cc, F) = que.front(); que.pop();

      if (get<0>(F) + get<1>(F) + get<2>(F) + get<3>(F) == M) {
         res = min(res, Cost);
         continue;
      }

      int nr, nc;

      // Knight 
      for (int i = 0; i < 8; ++i) {
         nr = cr + dirK[0][i], nc = cc + dirK[1][i]; if (oob(nr, nc)) continue;
         fed nF = {
            food[nr][nc]==1 || get<0>(F), food[nr][nc]==2 || get<1>(F),
            food[nr][nc]==3 || get<2>(F), food[nr][nc]==4 || get<3>(F)
         };
         if (dup[nr][nc][get<0>(nF)][get<1>(nF)][get<2>(nF)][get<3>(nF)] <= Cost + cost[0]) continue;

         dup[nr][nc][get<0>(nF)][get<1>(nF)][get<2>(nF)][get<3>(nF)] = Cost + cost[0];
         que.push({Cost + cost[0], nr, nc, nF});
      }

      // Bishop
         // - -
         nr = cr, nc = cc;
      while (!oob(nr, nc)) {
         if (nr == cr && nc == cc) {
            nr -= 1, nc -= 1;
            continue;
         }
         fed nF = {
            food[nr][nc]==1 || get<0>(F), food[nr][nc]==2 || get<1>(F),
            food[nr][nc]==3 || get<2>(F), food[nr][nc]==4 || get<3>(F)
         };
         if (dup[nr][nc][get<0>(nF)][get<1>(nF)][get<2>(nF)][get<3>(nF)] <= Cost + cost[1]) {
            nr -= 1, nc -= 1;
            continue;
         }

         dup[nr][nc][get<0>(nF)][get<1>(nF)][get<2>(nF)][get<3>(nF)] = Cost + cost[1];
         que.push({Cost + cost[1], nr, nc, nF});

         nr -= 1, nc -= 1;
      }
         // - +
         nr = cr, nc = cc;
      while (!oob(nr, nc)) {
         if (nr == cr && nc == cc) {
            nr -= 1, nc += 1;
            continue;
         }
         fed nF = {
            food[nr][nc]==1 || get<0>(F), food[nr][nc]==2 || get<1>(F),
            food[nr][nc]==3 || get<2>(F), food[nr][nc]==4 || get<3>(F)
         };
         if (dup[nr][nc][get<0>(nF)][get<1>(nF)][get<2>(nF)][get<3>(nF)] <= Cost + cost[1]) {
            nr -= 1, nc += 1;
            continue;
         }

         dup[nr][nc][get<0>(nF)][get<1>(nF)][get<2>(nF)][get<3>(nF)] = Cost + cost[1];
         que.push({Cost + cost[1], nr, nc, nF});

         nr -= 1, nc += 1;
      }
         // + -
         nr = cr, nc = cc;
      while (!oob(nr, nc)) {
         if (nr == cr && nc == cc) {
            nr += 1, nc -= 1;
            continue;
         }
         fed nF = {
            food[nr][nc]==1 || get<0>(F), food[nr][nc]==2 || get<1>(F),
            food[nr][nc]==3 || get<2>(F), food[nr][nc]==4 || get<3>(F)
         };
         if (dup[nr][nc][get<0>(nF)][get<1>(nF)][get<2>(nF)][get<3>(nF)] <= Cost + cost[1]) {
            nr += 1, nc -= 1;
            continue;
         }

         dup[nr][nc][get<0>(nF)][get<1>(nF)][get<2>(nF)][get<3>(nF)] = Cost + cost[1];
         que.push({Cost + cost[1], nr, nc, nF});

         nr += 1, nc -= 1;
      }

         // + +
         nr = cr, nc = cc;
      while (!oob(nr, nc)) {
         if (nr == cr && nc == cc) {
            nr += 1, nc += 1;
            continue;
         }
         fed nF = {
            food[nr][nc]==1 || get<0>(F), food[nr][nc]==2 || get<1>(F),
            food[nr][nc]==3 || get<2>(F), food[nr][nc]==4 || get<3>(F)
         };
         if (dup[nr][nc][get<0>(nF)][get<1>(nF)][get<2>(nF)][get<3>(nF)] <= Cost + cost[1]) {
            nr += 1, nc += 1;
            continue;
         }

         dup[nr][nc][get<0>(nF)][get<1>(nF)][get<2>(nF)][get<3>(nF)] = Cost + cost[1];
         que.push({Cost + cost[1], nr, nc, nF});

         nr += 1, nc += 1;
      }

      // Rook
         // hor
         nr = cr;
      for (int i = 0; i < N; ++i) {
         nc = i; if (nc == cc) continue;
         fed nF = {
            food[nr][nc]==1 || get<0>(F), food[nr][nc]==2 || get<1>(F),
            food[nr][nc]==3 || get<2>(F), food[nr][nc]==4 || get<3>(F)
         };
         if (dup[nr][nc][get<0>(nF)][get<1>(nF)][get<2>(nF)][get<3>(nF)] <= Cost + cost[2]) continue;

         dup[nr][nc][get<0>(nF)][get<1>(nF)][get<2>(nF)][get<3>(nF)] = Cost + cost[2];
         que.push({Cost + cost[2], nr, nc, nF});
      }
         // ver
         nc = cc;
      for (int i = 0; i < N; ++i) {
         nr = i; if (nr == cc) continue;
         fed nF = {
            food[nr][nc]==1 || get<0>(F), food[nr][nc]==2 || get<1>(F),
            food[nr][nc]==3 || get<2>(F), food[nr][nc]==4 || get<3>(F)
         };
         if (dup[nr][nc][get<0>(nF)][get<1>(nF)][get<2>(nF)][get<3>(nF)] <= Cost + cost[2]) continue;

         dup[nr][nc][get<0>(nF)][get<1>(nF)][get<2>(nF)][get<3>(nF)] = Cost + cost[2];
         que.push({Cost + cost[2], nr, nc, nF});
      }

   }
}

int main() {
   ios::sync_with_stdio(0); cin.tie(0);

   cin >> N;
   cin >> cost[0] >> cost[1] >> cost[2];
   cin >> init.first >> init.second;
   cin >> M;

   fill(&dup[0][0][0][0][0][0], &dup[0][0][0][0][0][0] + 50*50*2*2*2*2, INF);

   for (int i = 0, r, c; i < M; ++i) {
      cin >> r >> c;
      food[r][c] = i + 1;
   }

   bfs();

   cout << res << endl;
   
   return_0;
}