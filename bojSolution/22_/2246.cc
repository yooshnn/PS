#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;
using elem = tuple<int, int, int>;

vector<elem> v;
set<int> res;
int m;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n; cin >> n;

  if (n == 1) assert(0);

  v.resize(n);
  for (int i = 0, q, w; i < n; ++i) {
    cin >> q >> w;
    v[i] = {q, w, i};
  }

  sort(all(v), [](elem &lhs, elem &rhs) {
    return get<0>(lhs) < get<0>(rhs);
  });
  m = 20000;
  for (int i = 0; i < n; ++i) {
    if (m > get<1>(v[i])) {
      res.insert(get<2>(v[i]));
    }
    m = min(m, get<1>(v[i]));
  }

  sort(all(v), [](elem &lhs, elem &rhs) {
    return get<1>(lhs) < get<1>(rhs);
  });
  m = 20000;
  for (int i = 0; i < n; ++i) {
    if (m <= get<0>(v[i])) {
      res.erase(get<2>(v[i]));
    }
    m = min(m, get<0>(v[i]));
  }

  cout << res.size();


  sad;
}
