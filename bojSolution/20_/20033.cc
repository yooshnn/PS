#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector<int> s;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 0, t; i < N; ++i) {
    cin >> t;
    s.push_back(t);
  }

  int lp = 1, rp = 1000000000, mid, res = 0;
  while (lp <= rp) {
    mid = (lp + rp) / 2;
    int cnt = 0, good = false;
    for (int i = 0; i < N; ++i) {
      if (s[i] >= mid) cnt += 1;
      else cnt = 0;
      if (cnt == mid) {
        good = true;
        break;
      }
    }
    if (good) {
      lp = mid + 1;
      res = max(res, mid);
    }
    else rp = mid - 1;
  }

  cout << res;

}