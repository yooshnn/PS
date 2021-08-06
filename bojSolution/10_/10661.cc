#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tup = tuple<int, int, int>;

int root[1010];

int dsfind(int tar) {
  if (tar == root[tar]) return tar;
  return root[tar] = dsfind(root[tar]);
}
void dsmerge(int a, int b) {
  a = dsfind(a), b = dsfind(b);
  if (a != b) root[a] = b;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int N, M;
  while ((cin >> N >> M) && N) {
    priority_queue<tup, vector<tup>, greater<tup>> que;
    for (int i = 0, u, v, w; i < M; ++i) {
      cin >> u >> v >> w;
      que.push({w, u, v});
    }
    for (int i = 1; i <= N; ++i) root[i] = i;

    int cnt = 0;
    vector<int> res;
    while (!que.empty() && cnt < N-1) {
      auto [w, u, v] = que.top(); que.pop();
      if (dsfind(u) == dsfind(v)) continue;
      dsmerge(u, v);
      res.push_back(w);
    }
    sort(res.begin(), res.end());

    cout << res[N/2 - 1] << "\n";
  }

  sad;
  
}