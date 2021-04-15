#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;

int N, x;
vector<int> s, u;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 0, t; i < N; ++i) {
    cin >> t;
    s.push_back(t);
    if (i == 0 || s[i-1] != s[i]) u.push_back(t);
  }

  int lp = 0, rp = u.size() - 1, mid, res = (N == 1);
  while (lp <= rp) {
    mid = (lp + rp) / 2;
    int pos = lower_bound(s.begin(), s.end(), u[mid]) - s.begin();
    int pp = s[pos] + pos;
    while (pos != N-1 && pp > s[pos+1]) pp++, pos++;
    if (pos == N-1) {
      res = true;
      x = lower_bound(s.begin(), s.end(), u[mid]) - s.begin();
      rp = mid - 1;
    }
    else {
      lp = mid + 1;
    }
  }

  if (res) {
    for (; x < N; ++x) {
      if (x == 0 || s[x-1] != s[x]) cout << x + 1 << " ";
    }
  }
  else cout << -1;

}