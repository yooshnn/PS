#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tup;

int dirK[2][8] {{-1, -2, -2, -1, 1, 2, 2, 1}, {2, 1, -1, -2, -2, -1, 1, 2}};

inline bool oob(int r, int c) {
   return (r < 0 || c < 0 || r >= 8 || c >= 8);
}

pii parse(string s) {
   return {s[0]-'a', s[1]-'1'};
}

void solve(string s, string t) {

   pii p0 = parse(s), p1 = parse(t);

   int dup[8][8]; fill(&dup[0][0], &dup[0][0]+64, 10000);
   dup[p0.first][p0.second] = 0;

   int cr, cc, T, nr, nc;
   queue<tup> que; 

   for (que.push({p0.first, p0.second, 0}); !que.empty(); que.pop()) {
      tie(cr, cc, T) = que.front();
      if (cr == p1.first && cc == p1.second) continue;
      for (int i = 0; i < 8; ++i) {
         nr = cr + dirK[0][i], nc = cc + dirK[1][i];
         if (oob(nr, nc) || dup[nr][nc] <= T+1) continue;
         dup[nr][nc] = T+1;
         que.push({nr, nc, T+1});
      }
   }

   cout << "To get from " << s << " to " << t << " takes " << dup[p1.first][p1.second] << " knight moves.\n";

}

int main() {
   ios::sync_with_stdio(0); cin.tie(0);

   string s, t;
   while (cin >> s) {
      cin >> t;
      solve(s, t);
   }

   return_0;
}