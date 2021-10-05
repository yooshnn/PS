#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int SIZE = 1010, INF = 0x3f3f3f3f;

int N, res[SIZE], arr[SIZE];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 0, u, v; i < N; ++i) {
    cin >> u >> v;
    arr[u] = v;
  }

  int m;

  m = 0;
  for (int i = 1; i <= 1000; ++i) {
    m = max(m, arr[i]);
    res[i] = m;
  }
  m = 0;
  for (int i = 1000; i >= 1; --i) {
    m = max(m, arr[i]);
    res[i] = min(res[i], m);
  }

  cout << accumulate(&res[0], &res[0]+SIZE, 0);
  
  sad;
}
