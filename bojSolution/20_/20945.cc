#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 2e8;

int N, K;
int res = INF;
vector<int> v;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> K;

  v.resize(2*N);
  for (int i = 0; i < N; ++i) {
    cin >> v[i];
    v[i+N] = v[i];
  }

  int lp = 0, rp = 0, prv = INF;
  bool dup = false;
  set<int> p;
  p.insert(v[rp]);

  while (1) {
    if (dup) {
      dup = false;
      while (v[lp] != v[rp]) {
        p.erase(v[lp]);
        lp += 1;
      }
      lp += 1;
    }
    
    int temp = K - (rp - lp + 1);

    if (*p.rbegin() - *p.begin() + 1 > K) {
      p.erase(v[lp]);
      lp += 1;
    }
    else {
      res = min(res, temp);
      rp += 1;
      if (rp == 2*N) break;
      if (p.find(v[rp]) != p.end()) dup = true;
      p.insert(v[rp]);
    }
  }

  cout << res;


  sad;
}