#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tup = tuple<int, int, int>;

const int INF = 0x3f3f3f3f;

int N;
vector<tup> qu;
vector<int> a;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  a.resize(N+1, 0);

  for (int i = 1, u, v; i <= N; ++i) {
    cin >> u >> v;
    qu.push_back({u, 0, i});
    qu.push_back({v, 1, i});
  }
  sort(all(qu));

  set<int> pool;
  int las, res = 0, sub = INF;

  for (auto [p, _, i] : qu) {
    int x = *pool.begin();
    if (pool.size() == 1) a[x] += p - las;
    if (pool.size() >= 1) res += p - las;
    if (!pool.erase(i)) pool.insert(i);
    las = p;
  }

  for (int i = 1; i <= N; ++i) sub = min(sub, a[i]);
  cout << res - sub;
    // cout << " i : " << i << " ~ " << a[i] << endl;
  // cout << res << " - " << sub;
  
  sad;
}