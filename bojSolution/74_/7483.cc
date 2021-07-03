#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define sad std::cout.flush(), system("pause")
using namespace std;

int n;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  while (cin >> n) {
    if (n == 0) break;

    vector<int> s(n);
    for (int& i : s) cin >> i;
    sort(s.begin(), s.end());

    for (int i = 0; i < n-1; ++i) {
      if (s[i]+1 == s[i+1]) {
        int p = upper_bound(s.begin() + i, s.end(), s[i+1]) - s.begin();
        if (p != n) {
          swap(s[i+1], s[p]);
        }
        else {
          p = i;
          while (s[p]+1 == s[p+1]) {
            swap(s[p], s[p+1]);
            p -= 1;
          }
        }
      }
    }

    for (int c : s) cout << c << ' ';
    cout << '\n';
  }

}