#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;
using ll = long long;

ll N, res;
vector<ll> x, y;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (ll i = 0, a, b; i < N; ++i) {
    cin >> a >> b;
    x.push_back(a);
    y.push_back(b);
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  ll psumx = 0, psumy = 0;
  for (ll i = 0; i < N; ++i) {
    res += x[i] * i - psumx;
    res += y[i] * i - psumy;
    psumx += x[i];
    psumy += y[i];
  }

  cout << res;
}