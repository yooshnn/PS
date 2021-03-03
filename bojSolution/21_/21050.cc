#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;
using ll = long long;

struct dam {
  int par;
  ll cap, cur, pp;
  vector<int> child;

  dam() { par = cap = cur = pp = -1; }

} T[200010];

ll res;

void solve(int id) {
  T[id].pp = T[id].cap - T[id].cur + max(0LL, T[T[id].par].pp - T[id].cap);
  res = min(res, T[id].pp);
  for (int nxt : T[id].child) {
    solve(nxt);
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  dam &root = T[0];

  int n;
  cin >> n >> root.pp;

  for (int i = 1; i <= n; ++i) {
    cin >> T[i].par >> T[i].cap >> T[i].cur;
    T[T[i].par].child.push_back(i);
  }

  res = T[0].pp;
  for (int i : root.child) {
    solve(i);
  }

  cout << res;
  
}