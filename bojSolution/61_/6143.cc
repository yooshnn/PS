#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;

int N, x;
string s;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  s.resize(N);
  for (char &c : s) cin >> c;
  
  int lp = 0, rp = N-1;
  while (lp <= rp) {
    int f = 0, a = lp, b = rp;
    for (; a < b; ++a, --b) {
      if (s[a] != s[b]) { f = (s[b] < s[a]); break; }
    }
    cout << s[(f ? rp-- : lp++)];
    if (++x % 80 == 0) cout << "\n";
  }

  sad;
}