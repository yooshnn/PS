#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;

int n, t;
vector<int> lis;
vector<pii> org;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> n;

  org.resize(n);

  for (int i = 0; i < n; ++i) {
    cin >> t;
    int lo = lower_bound(lis.begin(), lis.end(), t) - lis.begin();
    if (lo == lis.size()) lis.push_back(t);
    else lis[lo] = t;
    org[i] = {lo, t};
  }
  
  int cur = lis.size() - 1;
  deque<int> res;
  for (int i = n - 1; i >= 0; --i) {
    if (org[i].first == cur) {
      res.push_front(org[i].second);
      cur -= 1;
    }
  }

  cout << lis.size() << "\n";
  for (int i : res) cout << i << " ";

}