#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int K, N;
string t;
vector<string> v;

bool cmp(const string &lhs, const string &rhs) {
  return lhs+rhs > rhs+lhs;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> K >> N;
  
  v.resize(K);
  for (string &i : v) {
    cin >> i;
    if (i.size() > t.size() || (i.size() == t.size() && i > t)) t = i;
  }

  sort(v.begin(), v.end(), cmp);

  for (string &i : v) {
    if (i.size() == t.size()) {
      for (int j = 0; j < N-K; ++j) cout << t;
      t = "";
    }
    cout << i;
  }
  
  sad;
}