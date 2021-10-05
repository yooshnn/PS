#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
string res;
vector<string> v;

bool cmp(const string &lhs, const string &rhs) {
  return lhs+rhs < rhs+lhs;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  
  v.resize(N);
  for (string &i : v) cin >> i;

  sort(v.begin(), v.end(), cmp);

  if (v[0][0] == '0') {
    bool f = false;
    for (int i = 0; i < N; ++i) {
      if (v[i][0] != '0') {
        f = true;
        string temp = v[i];
        for (int j = 0; j < N; ++j) {
          if (i == j) continue;
          string &x = v[j];
          for (char &y : x) temp.push_back(y);
        }
        res = (res.empty() ? temp : min(res, temp));
      }
    }
    if (f) return cout << res, 0;
    else return cout << "INVALID", 0;
  }

  for (string &i : v) {
    cout << i;
  }
  
  sad;
}