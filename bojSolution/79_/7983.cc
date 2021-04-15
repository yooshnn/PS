#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;

int n, res;
bool cmp(pii &lhs, pii &rhs) {
  return lhs.second > rhs.second;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  
  cin >> n;
  vector<pii> hw(n);

  for (pii &i : hw) cin >> i.first >> i.second;

  sort(hw.begin(), hw.end(), cmp);
  
  res = 2e9 + 1;
  for (pii &i : hw) {
    if (res > i.second) {
      res = i.second - i.first;
    }
    else {
      res -= i.first;
    }
  }

  cout << res << endl;
  
}