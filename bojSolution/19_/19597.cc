#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

struct Graph {
   int cap;
   string res;
   vector<vector<int>> adj;

   Graph(int N) {
      cap = 2*N;
      res = string(N, '-');
      adj.resize(cap);
   }

   void addEdge(int u, int v) {
      adj[u].push_back(v);
   }

   bool solve(int d) {
      sort(adj[d].begin(), adj[d].end());
      for (int& next: adj[d]) {
         bool req = solve(next);
         if (!req) continue;
         res[d/2] = (d&1 ? '1' : '0');
         return true;
      }
      if (d >= cap - 2) {
         res[d/2] = (d&1 ? '1' : '0');
         return true;
      }
      return false;
   }
};

int main() {
   ios::sync_with_stdio(0); cin.tie(0);

   int TEST; cin >> TEST; while (TEST--) {
      int N; cin >> N;
      Graph G(N);
      vector<string> s(N); for (string& x : s) cin >> x;
      for (int i = 0; i < N-1; ++i) {
         if (s[i] < s[i+1]) G.addEdge(i*2, (i+1)*2);
         reverse(s[i+1].begin(), s[i+1].end());
         if (s[i] < s[i+1]) G.addEdge(i*2, (i+1)*2+1);
         reverse(s[i].begin(), s[i].end());
         if (s[i] < s[i+1]) G.addEdge(i*2+1, (i+1)*2+1);
         reverse(s[i+1].begin(), s[i+1].end());
         if (s[i] < s[i+1]) G.addEdge(i*2+1, (i+1)*2);
      }
      G.solve(0);
      bool good = true;
      for (char& c : G.res) {
         if (c == '-') good = false;
      }
      if (!good) G.solve(1);
      for (char& c : G.res) {
         if (c == '-') assert(0);
      }
      cout << G.res << "\n";
   }

   return_0;
}