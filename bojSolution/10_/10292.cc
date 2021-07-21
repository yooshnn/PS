#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using ll = long long;

int V, E, gid;
int order[30010], isCutVertex[30010];
vector<int> adj[30010];

int dfs(int id, bool isRoot) {
  order[id] = ++gid;
  int ret = order[id];

  int child = 0;
  for (int &i : adj[id]) {
    if (!order[i]) {
      child += 1;
      int low = dfs(i, false);
      if (!isRoot && low >= order[id]) isCutVertex[id] = true;
      ret = min(ret, low);
    }
    else {
      ret = min(ret, order[i]);
    }
  }

  if (isRoot) isCutVertex[id] = (child >= 2);
  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int TEST; cin >> TEST; while (TEST--) {

    cin >> V >> E;

    for (int i = 0, u, v; i < E; ++i) {
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dfs(1, true);

    bool res = false;
    for (int i = 1; i <= V; ++i) {
      if (isCutVertex[i]) res = true;
      adj[i].clear();
      order[i] = isCutVertex[i] = 0;
    }
    gid = 0;

    if (res) cout << "YES\n";
    else cout << "NO\n";
  }

}