#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

  int TEST; cin >> TEST; while (TEST--) {
    int B, P, Q; cin >> B >> P >> Q;
    Bit T(B);

    P += Q;
    while (P--) {
      char a; int b, c;
      cin >> a >> b >> c;
      if (a == 'P') T.update(b, c);
      else cout << T.query(b, c) << "\n";
    }
  }


  sad;
}