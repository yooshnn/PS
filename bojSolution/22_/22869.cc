#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, K, arr[5010], dup[5010];
queue<int> que;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> K;
  for (int i = 1; i <= N; ++i) cin >> arr[i];
    
  dup[1] = true;
  for (que.push(1); !que.empty(); que.pop()) {
    int u = que.front();
    for (int v = u+1; v <= N; ++v) {
      if (v-u > K) break;
      int p = (v-u)*(1+abs(arr[v]-arr[u]));
      if (p <= K && !dup[v]) que.push(v), dup[v] = true;
    }
  }

  cout << (dup[N] ? "YES" : "NO");

  sad;

}
