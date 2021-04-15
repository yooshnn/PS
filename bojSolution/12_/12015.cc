#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;

int n, t;
vector<int> lis;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> n;
  while (n--) {
    cin >> t;
    int lo = lower_bound(lis.begin(), lis.end(), t) - lis.begin();
    if (lo == lis.size()) lis.push_back(t);
    else {
      lis[lo] = t;
    }
  }
  cout << lis.size();

}