#define sad return 0
#include <bits/stdc++.h>
using namespace std;

int N, res = 0;
stack<int> s;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;

  for (int i = 0, t; i < N; ++i) {
    cin >> t;

    while (!s.empty() && s.top() > t) s.pop();
    if (t == 0) continue;
    if (s.empty() || s.top() != t) s.push(t), res += 1;
  }
  
  cout << res;

  sad;

}
