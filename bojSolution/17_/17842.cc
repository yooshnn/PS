#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;

int N, cnt = 1;
bool dup[200010];
vector<int> adj[200010];

int solve() {
  queue<int> que;
  dup[0] = true;
  for (que.push(0); !que.empty(); que.pop()) {
    int cur = que.front();
    if (adj[cur].size() == 1) cnt++;
    for (int i : adj[cur]) {
      if (dup[i]) continue; dup[i] = true;
      que.push(i);
    }
  }
  return cnt/2;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;

  while (--N) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  cout << solve();

}