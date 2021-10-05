#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int X, Y, Z, res = 1e8;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> X >> Y >> Z;

  for (int i = 1; X*i < Z; ++i) {
    res = min(res, (Z-X*i)%Y);
  }

  cout << Z - res;
  
  sad;
}
