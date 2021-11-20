#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int
  N, res,
  arr[22];
set<int> p;

void dfs(int i, int j) {
  p.insert(j);
  if (i==N) return;
  dfs(i+1, j+arr[i+1]);
  dfs(i+1, j);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> arr[i];
    res += arr[i];
  }

  dfs(0, 0);
  cout << 1 + res - (int)p.size();
  
  sad;
}
