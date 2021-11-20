#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Segt {
  using T = ll;

  static constexpr T def = 0;
  int cap; vector<T> seg;

  Segt(int c = 0, T d = def) : seg(2*(c+1), d), cap(c+1) {}

  T segfun(T i, T j) { return i + j; }
  void update(int i, T v) {
    for (seg[i += cap] = v; i >>= 1; ) {
      seg[i] = segfun(seg[i<<1], seg[(i<<1)^1]);
    }
  }
  T ask(int l, int r) {
    T r1 = def, r2 = def;
    for (l += cap, r += cap; l <= r; l >>= 1, r >>= 1) {
      if (l&1) r1 = segfun(r1, seg[l++]);
      if (~r&1) r2 = segfun(r2, seg[r--]);
    }
    return segfun(r1, r2);
  }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  
  int N, Q1, Q2; cin >> N >> Q1 >> Q2;
  Q1 += Q2;

  Segt T(N);
  for (int i = 1; i <= N; ++i) {
    ll t; cin >> t;
    T.update(i, t);
  }
  for (ll a, b, c; Q1--; ) {
    cin >> a >> b >> c;
    if (a == 1) T.update(b, c);
    else cout << T.ask(b, c) << "\n";
  }

  sad;
}