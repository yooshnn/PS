#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int N; cin >> N;
  vector<int> s(N, 0);
  for (int &i : s) cin >> i;
  next_permutation(s.begin(), s.end());

  bool flag = false;
  for (int i = 0; i < N; ++i) {
    if (s[i] != i+1) break;
    if (i == N-1) flag = true;
  }
  if (flag) cout << -1;
  else for (int i : s) cout << i << " ";

}