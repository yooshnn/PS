#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;

int a, b, x, y;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> a >> b >> x >> y;
  int res = abs(a-b);
  res = min({res, abs(a-x) + abs(b-y), abs(a-y) + abs(b-x)});
  cout << res;


  sad;
}
