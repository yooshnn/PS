#include <bits/stdc++.h>
using namespace std;
#define sad cout.flush(), system("pause")
typedef long long ll;
typedef pair<int, int> pii;

const int INF = 1e8;

int N, P, Q;
int pathLen;
vector<int> path, esc[3];
vector<int> res[3];

struct Segt {
   int depth, f;
   int* tree;

   Segt() {}
   Segt(int n) {
      tree = new int[n * 4];
      fill(tree, tree + n * 4, 0);
      for (depth = 1; n > (int)pow(2, depth - 1); ++depth);
      f = (int)pow(2, depth - 1) - 1;
   }

   void build() {
      for (int i = depth - 1; i >= 1; --i) {
         for (int j = 0; j < (int)pow(2, i - 1); ++j) {
            int cur = (int)pow(2, i - 1) + j;
            tree[cur] = max(tree[cur * 2], tree[cur * 2 + 1]);
         }
      }
   }

   int ask(int p, int q) {
      int ret = 0; p += f, q += f;
      while (p <= q) {
         if (p % 2 == 1) ret = max(ret, tree[p]);
         if (q % 2 == 0) ret = max(ret, tree[q]);
         p = (p + 1) / 2, q = (q - 1) / 2;
      }
      return ret;
   }

} T1, T2;
struct Graph {
   int cap;
   vector<vector<int>> adj;
   vector<int> dup;

   Graph(int n) {
      cap = n+1;
      dup.resize(cap, -1);
      adj.resize(cap);
   }

   void addEdge(int u, int v) {
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   void process(int u, int v) {
      dup[u] = 0;
      queue<int> que;
      for (que.push(u); !que.empty(); que.pop()) {
         int cur = que.front();
         if (cur == v) {
            while (cur != 0) {
               path.push_back(cur);
               cur = dup[cur];
            }
            break;
         }
         else {
            for (int& next: adj[cur]) {
               if (dup[next] != -1) continue;
               dup[next] = cur;
               que.push(next);
            }
         }
      }
      pathLen = path.size();
      calc();
   }

   void calc() {
      esc[1].resize(pathLen + 1, INF);
      esc[2].resize(pathLen + 1, INF);
      memset(&dup[0], 0, sizeof(int)*cap);
      for (int& x : path) dup[x] = 1;

      for (int i = 0; i < pathLen; ++i) {
         int req = 0;
         for (int& next: adj[path[i]]) {
            if ((i>0 && next==path[i-1]) || (i<pathLen && next==path[i+1])) continue;
            req = max(req, dfs(next));
         } 
         esc[2][pathLen - i] = req + i + 1;
         esc[1][pathLen - i] = req + pathLen - i;
      }
   }

   int dfs(int id) {
      int ret = 0;
      dup[id] = 1;
      for (int& next: adj[id]) {
         if (dup[next] == 1) continue;
         ret = max(ret, dfs(next));
      }
      return ret + 1;
   }
};

int solve(int tt, int lp, int rp) {
   int ret;
   if (tt) {
      if (res[1][lp] != -INF) return res[1][lp];
      ret = -INF;
      if (lp + 1 != rp) ret = solve(tt ^ 1, lp + 1, rp);
      res[1][lp] = ret = max(ret, esc[1][lp] - T2.ask(lp + 1, rp));
   }
   else {
      if (res[2][rp] != INF) return res[2][rp];
      ret = INF;
      if (rp - 1 != lp) ret = solve(tt ^ 1, lp, rp - 1);
      res[2][rp] = ret = min(ret, T1.ask(lp, rp - 1) - esc[2][rp]);
   }
   return ret;
}

int main() {
   ios::sync_with_stdio(0), cin.tie(0);

   cin >> N >> P >> Q;
   Graph G(N);
   for (int i = 0, u, v; i < N-1; ++i) {
      cin >> u >> v;
      G.addEdge(u, v);
   } G.process(P, Q);

   T1 = Segt(pathLen), T2 = Segt(pathLen);
   for (int i = 1; i <= pathLen; ++i) T1.tree[T1.f + i] = esc[1][i];
   for (int i = 1; i <= pathLen; ++i) T2.tree[T2.f + i] = esc[2][i];
   T1.build(), T2.build();

   res[1].resize(pathLen + 1, -INF);
   res[2].resize(pathLen + 1, INF);

   solve(1, 1, pathLen);
   cout << res[1][1];

}