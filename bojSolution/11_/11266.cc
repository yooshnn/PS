#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using ll = long long;

int V, E, gid;
int order[10010], isCutVertex[10010];
vector<int> adj[10010];

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

  cin >> V >> E;

  for (int i = 0, u, v; i < E; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= V; ++i) {
    if (order[i] == 0) dfs(i, true);
  }

  int res = 0;
  for (int i = 1; i <= V; ++i) {
    if (isCutVertex[i]) res += 1;
  }
  cout << res << "\n";
  for (int i = 1; i <= V; ++i) {
    if (isCutVertex[i]) cout << i << " ";
  }

}