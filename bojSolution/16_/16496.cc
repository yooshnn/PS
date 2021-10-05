#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
vector<string> v;

bool cmp(const string &lhs, const string &rhs) {
  return lhs+rhs > rhs+lhs;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  
  v.resize(N);
  for (string &i : v) cin >> i;

  sort(v.begin(), v.end(), cmp);

  if (v[0] == "0") return cout << 0, 0;

  for (string &i : v) {
    cout << i;
  }
  
  sad;
}