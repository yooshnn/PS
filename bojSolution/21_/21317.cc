#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;
using tup = tuple<int, int, int>; // ind, energy, leap

int n, k, res = 2e8;
vector<pii> energy;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> n;

  energy.resize(n+1, {0, 0});

  for (int i = 0; i < n-1; ++i) {
    cin >> energy[i].first >> energy[i].second;
  }

  cin >> k;

  queue<tup> que;
  for (que.push({0, 0, 0}); !que.empty(); que.pop()) {
    auto[ind, pp, leap] = que.front();
    if (ind >= n) continue;
    if (ind == n-1) {
        res = min(res, pp);
        continue;
    }
    if (leap == 0) {
      que.push({ind + 3, pp + k, 1});
      que.push({ind + 2, pp + energy[ind].second, 0});
      que.push({ind + 1, pp + energy[ind].first, 0});
    }
    else {
      que.push({ind + 2, pp + energy[ind].second, 1});
      que.push({ind + 1, pp + energy[ind].first, 1});
    }
  }

  cout << res;

}