#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int N;
vector<int> res;

struct Node {
  ll U, M, I, indeg;
  vector<pll> adj; // {v, p} sends p% to v
};
vector<Node> graph;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  graph.resize(N + 1);

  for (int i = 1, t; i <= N; ++i) {
    cin >> graph[i].M >> t;
    graph[i].M *= 100000;
    for (int j = 0; j < t; ++j) {
      ll v, p;
      cin >> v >> p;
      graph[i].adj.push_back({v, p});
      graph[v].indeg += 1;
    }
  }

  queue<int> que, seq;
  for (int i = 1; i <= N; ++i) {
    if (graph[i].indeg == 0) que.push(i), graph[i].I = graph[i].M;
  }
  for (int i = 1; i <= N; ++i) {
    assert(!que.empty());
    seq.push(que.front());
    for (pll& x : graph[que.front()].adj) {
      if (--graph[x.first].indeg == 0) que.push(x.first);
    } que.pop();
  }

  for (int c; !seq.empty(); seq.pop()) {
    c = seq.front();
    Node& cur = graph[c];

    cur.U = min(cur.I, cur.M);
    if (cur.U == cur.M) res.push_back(c);

    for (pll& x : cur.adj) {
      ll v, p; tie(v, p) = x;
      graph[v].I += (cur.U * p) / 100;
    }
  }

  sort(res.begin(), res.end());
  for (int& i : res) cout << i << " ";
  
}