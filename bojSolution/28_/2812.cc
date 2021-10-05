#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int N, M, K;
vector<int> s;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> K;
  M = N - K;

  for (int i = 0; i < N; ++i) {
    char _t; cin >> _t;
    int t = _t - '0';
    while (!s.empty() && K && s.back() < t) s.pop_back(), K--;
    s.push_back(t);
  }
  for (int i = 0; i < min((int)s.size(), M); ++i) cout << s[i];

  sad;
  
}