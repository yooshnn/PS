#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using ll = long long;

const int INF = 2e8;

int N, M;
int dy[1010][1010];
vector<int> adj[1010];

int solve(int v, int par) {
  // leaf
  if (v != 1 && adj[v].size() == 1) return dy[v][par];

  int ret = (v == 1 ? INF : dy[v][par]), csum = 0;

  for (int sub_v : adj[v]) {
    if (sub_v == par) continue;
    csum += solve(sub_v, v);
  }

  return min(ret, csum);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int _TEST; cin >> _TEST; while (_TEST--) {
    cin >> N >> M;
    
    for (int i = 1; i <= N; ++i) {
      adj[i].clear();
    }
    for (int i = 1, u, v, w; i <= M; ++i) {
      cin >> u >> v >> w;
      adj[u].push_back(v);
      adj[v].push_back(u);
      dy[u][v] = dy[v][u] = w;
    }

    cout << solve(1, 0) << "\n";
  }

}