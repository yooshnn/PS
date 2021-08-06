#define sad return 0
#include <bits/stdc++.h>
using namespace std;

int N, K, m = 1;
bool res = 1;

priority_queue<int, vector<int>, greater<int>> v;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> K;

  for (int i = 0, t; i < N; ++i) {
    cin >> t;
    v.push(t);
  }

  while (!v.empty() && res) {
    int cur = v.top(); v.pop();

    if (cur == m) m++;
    else if (cur < m) v.push(cur + K);
    else res = false;
  }

  cout << (res && --m == N ? 1 : 0);

  sad;
}