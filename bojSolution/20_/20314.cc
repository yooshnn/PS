#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
ll H[200010], T[200010], res[200010];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; ++i) cin >> H[i];
  for (int i = 1; i <= N-1; ++i) cin >> T[i];
  
  map<ll, int> hh;
  int bar, dist;
  
  bar = 1, dist = 0;
  for (int i = 1; i <= N; ++i) {
    hh[H[i]] += 1;
    dist += T[i];
    if (i != N && H[i+1] >= dist) {
      continue;
    }
    do {
      res[bar] = max(res[bar], hh.rbegin()->first);
      dist -= T[bar];
      hh[H[bar]] -= 1;
      if (!hh[H[bar]]) hh.erase(H[bar]);
      bar += 1;
    } while (bar != i+1 && H[i+1] < dist);
  }

  hh.clear();
  bar = N, dist = 0;
  for (int i = N; i >= 1; --i) {
    hh[H[i]] += 1;
    dist += T[i-1];
    if (i != 1 && H[i-1] >= dist) {
      continue;
    }
    do {
      res[bar] = max(res[bar], hh.rbegin()->first);
      dist -= T[bar-1];
      hh[H[bar]] -= 1;
      if (!hh[H[bar]]) hh.erase(H[bar]);
      bar -= 1;
    } while (bar != i-1 && H[i-1] < dist);
  }




  for (int i = 1; i <= N; ++i) cout << res[i] << " ";


  sad;
}