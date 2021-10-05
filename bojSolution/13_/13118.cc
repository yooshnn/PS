#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;

int v[4], x, y, r;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  
  for (int &i : v) cin >> i;
  cin >> x >> y >> r;

  for (int i = 0; i < 4; ++i) {
    if (v[i] ==x) return cout << i+1, 0;
  }
  cout << 0;
  
  sad;
}
