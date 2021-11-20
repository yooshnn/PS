#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;

int
  N, K, c,
  dup[3010];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  memset(dup, 0x3f3f3f3f, sizeof dup);
  
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    char t; cin >> t;
    c += (t == 'H');
  }

  queue<int> que;
  dup[c] = 0;
  for (que.push(c); !que.empty(); que.pop()) {
    int cur = que.front();
    if (cur == 0) break;
    
    for (int i = 0; i <= min(K, cur); ++i) {
      if (N - cur < K - i) continue;
      int nxt = cur - i + (K - i);
      if (0 <= nxt && nxt <= N && dup[nxt] > dup[cur]+1) {
        dup[nxt] = dup[cur]+1;
        que.push(nxt);
      }
    }
  }

  cout << (dup[0] == 0x3f3f3f3f ? -1 : dup[0]);
  
  sad;
}
