#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;
using elem = pair<string, int>;

int u, n;
vector<elem> v;
map<int, int> cnt;
set<pii> p;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> u >> n;
  v.resize(n);
  for (elem &i : v) {
    cin >> i.first >> i.second;
    cnt[i.second] += 1;
  }
  for (auto x : cnt) {
    p.insert({x.second, x.first});
  }

  int asdf = (*p.begin()).second;
  for (elem x : v) {
    if (x.second == asdf) {
      cout << x.first << " " << x.second;
      break;
    }
  }


  sad;
}
