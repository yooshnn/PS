#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

struct Graph {
   int cap;
   vector<bool> dup;
   vector<vector<int>> adj;

   Graph(int N) {
      cap = N+1;
      dup.resize(cap, false);
      adj.resize(cap);
   }

   void addEdge(int u, int v) {
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   int solve(int id) {
      int ret = 0, cc = 0;
      dup[id] = true;

      for (int& next: adj[id]) {
         if (!dup[next]) {
            ret += solve(next);
            cc += 1;
         }
      }

      int x = 1; while (x < cc+1) {
         x *= 2; ret += 1;
      }

      return ret;
   }
};

int main() {
   ios::sync_with_stdio(0); cin.tie(0);

   int N; cin >> N;
   Graph G(N);
   for (int i = 0, u, v; i < N-1; ++i) {
      cin >> u >> v;
      G.addEdge(u, v);
   }

   cout << N - 1 + G.solve(1);

   return_0;
}