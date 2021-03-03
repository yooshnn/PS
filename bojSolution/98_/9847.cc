#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using ll = long long;
using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  
  int vecSize[4]; for (int &i : vecSize) cin >> i;
  vector<int> v[4];

  for (int i = 0; i < 4; ++i) {
    v[i].resize(vecSize[i]);
    for (int &j : v[i]) cin >> j;
  }

  vector<tup> s[2];
  for (int i : v[0]) for (int j : v[1]) {
    s[0].push_back({i + j, i, j});
  }
  for (int i : v[2]) for (int j : v[3]) {
    s[1].push_back({-(i + j), i, j});
  }

  sort(s[0].begin(), s[0].end());
  sort(s[1].begin(), s[1].end());

  for (tup t : s[0]) {
    int cur = get<0>(t), lp = 0, rp = s[1].size() - 1, mid;
    while (lp <= rp) {
      mid = (lp + rp)/2;
      if (get<0>(s[1][mid]) == cur) {
        cout << get<1>(t) << " " << get<2>(t) << " " << get<1>(s[1][mid]) << " " << get<2>(s[1][mid]);
        return 0;
      }
      if (get<0>(s[1][mid]) > cur) {
        rp = mid - 1;
      }
      else {
        lp = mid + 1;
      }
    }
  }


  
}