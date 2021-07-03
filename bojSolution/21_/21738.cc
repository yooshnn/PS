#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;
using ll = long long;

const int INF = 2e9;

int N, S, P;
vector<int> adj[330000];
int dist[330000];
bool dup[330000];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  fill(&dist[0], &dist[0]+330000, INF);

  cin >> N >> S >> P;
  for (int i = 0, u, v; i < N-1; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  queue<pii> que;
  dup[P] = true;
  for (que.push({P, 0}); !que.empty(); que.pop()) {
    auto[cn, cd] = que.front();
    if (cn <= S) dist[cn] = cd;
    else {
      for (int nxt : adj[cn]) {
        if (dup[nxt]) continue;
        dup[nxt] = true;
        que.push({nxt, cd + 1});
      }
    }
  }

  sort(&dist[1], &dist[1] + S);

  cout << N - dist[1] - dist[2] - 1;
  
}