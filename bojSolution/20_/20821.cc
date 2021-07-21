#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using ll = long long;

ll N, M; // teams, car
ll res;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> M;

  priority_queue<ll, vector<ll>, greater<ll>> que;
  
  for (ll i = 0; i < M; ++i) que.push(i);
  
  for (ll u; N > 0; --N) {
    cin >> u;
    u = que.top() + u * M;
    que.pop();
    res = max(res, u);
    que.push(u);
  }
  cout << res;

}