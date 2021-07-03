#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
typedef long long ll;

struct Bit {
  ll cap;
  vector<ll> arr, tree;

  Bit(int size) {
    cap = size + 1;
    arr.resize(cap, 0);
    tree.resize(cap, 0);
  }

  void update(int i, ll x) {
    ll diff = x;
    arr[i] += x;
    while (i < cap) {
      tree[i] += diff;
      i += i & -i;
    }
  }
  ll query(int l, int r) const {
    return pquery(r) - pquery(l - 1);
  }
  ll pquery(int i) const {
    ll ret = 0;
    while (i > 0) {
      ret += tree[i];
      i -= i & -i;
    }
    return ret;
  }
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int N, X; cin >> N >> X;
  int M = 0, cnt = 0;
  Bit T(N);

  for (int i = 1, t; i <= N; ++i) {
    cin >> t;
    T.update(i, t);
  }

  for (int i = 1; i <= N - X + 1; ++i) {
    int req = T.query(i, i+X-1);
    if (req == M) cnt += 1;
    else if (req > M) {
      cnt = 1;
      M = req;
    }
  }

  if (M == 0) cout << "SAD";
  else cout << M << "\n" << cnt;

}