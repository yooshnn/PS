#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<pii> res;
ll pow3[20];

void solve(ll N, int t) {
  if (N == 1) res.push_back({t, 0});
  else if (N % 2 == 0) solve(N / 2, t + 1);
  else {
    int i = 19;
    while (pow3[i] > N) i -= 1;
    res.push_back({t, i});
    if (N != pow3[i]) {
      solve(N - pow3[i], t);
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  pow3[0] = 1;
  for (int i = 1; i < 20; ++i) pow3[i] = pow3[i-1] * 3LL;

  int TEST; cin >> TEST; while (TEST--) {
    ll N; cin >> N;
    solve(N, 0);
    cout << res.size() << "\n";
    for (pii &i : res) cout << i.first << " " << i.second << "\n";
    res.clear();
  }
}