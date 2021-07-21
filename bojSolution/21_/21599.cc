#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int N; cin >> N;
  vector<int> s(N);

  for (int &i : s) cin >> i;
  sort(s.rbegin(), s.rend());

  int res = 0;
  for (int i = 0; i < N; ++i) {
    if (s[i] == 0) break;
    res = max(res, i + s[i]);
  }

  cout << min(N, res);

}