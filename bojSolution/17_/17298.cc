#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;

int N;
vector<int> v;
stack<int> stk, res;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 0, t; i < N; ++i) {
    cin >> t;
    v.push_back(t);
  }

  for (auto i = v.rbegin(); i != v.rend(); ++i) {
    while (!stk.empty() && stk.top() <= *i) stk.pop();
    if (stk.empty()) res.push(-1);
    else res.push(stk.top());
    stk.push(*i);
  }

  while (!res.empty()) {
    cout << res.top() << " ";
    res.pop();
  }
}