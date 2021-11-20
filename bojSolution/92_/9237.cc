#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;

int n, res;
vector<int> t;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> n; t.resize(n);
  for (int &i : t) cin >> i;
  sort(all(t), [](int &l, int &r){return l>r;});
  for (int i = 0; i < n; ++i) res = max(res, t[i]+i+2);

  cout << res;

  sad;
}
