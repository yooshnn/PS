#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;

int N, res = 1;
bool dup[110];
vector<int> adj[110];

void dfs(int id) {
  dup[id] = true;
  for (int nxt : adj[id]) {
    if (nxt == N) continue;
    if (dup[nxt]) {
      res = 0;
      return;
    }
    dfs(nxt);
  }
  dup[id] = false;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 1, cnt, t; i < N; ++i) {
    cin >> cnt; while (cnt--) {
      cin >> t;
      adj[i].push_back(t);
    }
  }

  dfs(1);

  if (res) cout << "NO CYCLE";
  else cout << "CYCLE";

}