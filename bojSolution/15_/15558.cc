#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using tup = tuple<int, int, int>;

bool dup[2][100000];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n, k; cin >> n >> k;
  string l[2];
  cin >> l[0] >> l[1];

  queue<tup> que;
  int d = -1;
  for (que.push({0, 0, -1}); !que.empty(); que.pop()) {
    auto [lr, i, d] = que.front();
    if (i == n-1 || i + k >= n) return cout << 1, 0;
    if (l[lr][i+1] == '1' && !dup[lr][i+1]) {
      dup[lr][i+1] = true;
      que.push({lr, i+1, d+1});
    }
    if (l[lr][i-1] == '1' && d+1 < i-1 && !dup[lr][i-1]) {
      dup[lr][i-1] = true;
      que.push({lr, i-1, d+1});
    }
    if (l[lr^1][i+k] == '1' && !dup[lr^1][i+k]) {
      dup[lr^1][i+k] = true;
      que.push({lr^1, i+k, d+1});
    }
  }
  cout << 0;
}