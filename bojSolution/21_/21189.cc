#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;

int N, M; 
vector<int> adj[100010];
bool dup[100010];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> M;

  for (int i = 0, u, v; i < M; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  queue<pii> que;
  for (que.push({1, -1}); !que.empty(); que.pop()) {
    auto [c, d] = que.front();
    if (c == N) return cout << d, 0;
    for (int nxt : adj[c]) {
      if (dup[nxt]) continue;
      dup[nxt] = true;
      que.push({nxt, d+1});
    }
  }

}