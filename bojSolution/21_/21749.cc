#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  map<char, int> m;
  int h = 0;

  string s;
  while (cin >> s) {
    for (char c : s) m[c] += 1;
  }
  
  for (auto i : m) h = max(h, i.second);

  while (h != 0) {
    for (auto i : m) {
      if (i.second >= h) cout << '#';
      else cout << ' ';
    }
    cout << '\n';
    h -= 1;
  }
  for (auto i : m) cout << i.first;

}