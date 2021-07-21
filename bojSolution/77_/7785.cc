#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;

set<string> s;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int N; cin >> N;

  while (N--) {
    string t, u; cin >> t >> u;
    if (u[0] == 'e') s.insert(t);
    else s.erase(t);
  }

  stack<string> res;
  for (string i : s) {
    res.push(i);
  }

  while (!res.empty()) {
    cout << res.top() << '\n'; res.pop();
  }

}