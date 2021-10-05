#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;

ll N, K, res = ~(1LL<<63);
vector<ll> v;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> K;

  v.resize(N);
  for (ll &i : v) cin >> i;
  sort(all(v));

  for (int i = 1; i < N; ++i) {
    ll s = v[0]*i + v[i]*(N-i);
    res = min({ res, (K+s-1)/s });
  }

  cout << res;

  sad;
}