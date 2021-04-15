#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;
using ll = long long;

int N, res;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  if (N&1) return cout << "still running", 0;

  for (int i = 0, t, u; i < N; ++i) {
    cin >> u;
    if (i&1) res += u - t;
    else t = u;
  }
  cout << res;

}