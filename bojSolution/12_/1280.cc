#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;
using ll = long long;

const ll MOD = 1e9 + 7;

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

  int N, x;
  ll res = 1, temp;

  cin >> N;
  Bit t1(200100), t2(200100);

  cin >> x;
  x += 1;

  t1.update(x, 1);
  t2.update(x, x);

  for (int i = 1; i < N; ++i) {
    cin >> x;
    x += 1;

    // res *= (t1.query(1, x-1) * x - t2.query(1, x-1)) + (t2.query(x+1, 200010) - t1.query(x+1, 200010) * x);
    // res %= MOD;

    temp = (t1.query(1, x-1) * x - t2.query(1, x-1)) + (t2.query(x+1, 200010) - t1.query(x+1, 200010) * x);
    temp %= MOD;

    res = (res * temp) % MOD;

    t1.update(x, 1);
    t2.update(x, x);
  }

  cout << res << endl;

}