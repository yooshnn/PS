#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using tup = tuple<int, int, int>;

int N, M;
bool pp[1010];
int root[1010];
priority_queue<tup, vector<tup>, greater<tup>> adj;

int search(int i) {
  if (root[i] == i) return i;
  return root[i] = search(root[i]);
}
void merge(int i, int j) {
  int a = search(i), b = search(j);
  if (a != b) root[b] = a;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    char t; cin >> t;
    pp[i] = (t == 'M' ? false : true);

    root[i] = i;
  }

  for (int i = 0; i < M; ++i) {
    int u, v, w; cin >> u >> v >> w;
    adj.push({w, u, v});
  }

  int res = 0, cnt = 0;
  while (!adj.empty() && cnt != N-1) {
    auto[w, u, v] = adj.top(); adj.pop();
    if (pp[u] == pp[v] || search(u) == search(v)) continue;
    merge(u, v);
    res += w;
    cnt += 1;
  }

  if (cnt == N-1) cout << res;
  else cout << -1;

}