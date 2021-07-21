#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;

int V, E;
int dup[3010][3010];
vector<int> adj[3010];

int vv = 0;
bool go(int id, int depth) {
  if (depth == E) return true;
  for (int &i : adj[id]) {
    if (dup[id][i] == vv) continue;
    dup[id][i] = dup[i][id] = vv;
    return go(i, depth + 1);
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> V >> E;
  
  for (int i = 0; i < E; ++i) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= V; ++i) {
    vv = i;
    if (go(i, 0)) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  
}