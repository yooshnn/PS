#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;
using ll = long long;

ll N, M, t, m;
map<int, ll> r;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> M;

  for (ll i = 0; i < M; ++i) {
    int cur; cin >> cur;
    t += N;
    m += (i + 1) - r[cur];
    r[cur] += (i + 1) - r[cur];
    cout << t - m << "\n";
  }
  
}