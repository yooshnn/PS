#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using ll = long long;

int CASE = 0, reachableCnt = 0;
bool dup[200010], reachable[200010];
vector<int> adj[200010];

bool dfs(int id) {
  bool ret = true;

  if (!reachable[id]) {
    reachable[id] = true;
    reachableCnt += 1;
  }
  dup[id] = true;

  for (int nxt : adj[id]) {
    if (dup[nxt]) {
      dup[id] = false;
      return false;
    }
    ret &= dfs(nxt);
  }

  dup[id] = false;

  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  while (++CASE) {
    int u, v,
      root = -1,
      edgeCnt = 0, nodeCnt = 0;
    map<int, int> i2u, hasIndeg;

    reachableCnt = 0;

    while (cin >> u >> v) {
      if (u == -1) return 0;
      if (u == 0) break;
      
      if (i2u.find(u) == i2u.end()) {
        i2u[u] = nodeCnt;
        adj[nodeCnt].clear();
        nodeCnt += 1;
      }
      if (i2u.find(v) == i2u.end()) {
        i2u[v] = nodeCnt;
        adj[nodeCnt].clear();
        nodeCnt += 1;
      }
      u = i2u[u];
      v = i2u[v];

      adj[u].push_back(v);
      hasIndeg[v] = 1;
      edgeCnt += 1;
    }

    for (int i = 0; i < nodeCnt; ++i) {
      if (hasIndeg[i] == 0) {
        if (root == -1) root = i;
        else root = -2;
      }
      dup[i] = false;
      reachable[i] = false;
    }

    cout << "Case " << CASE << " ";
    if (nodeCnt == 0 || (root >= 0 && edgeCnt + 1 == nodeCnt && dfs(root) && reachableCnt == nodeCnt)) cout << "is a tree.";
    else cout << "is not a tree.";
    cout << "\n";

  }

}