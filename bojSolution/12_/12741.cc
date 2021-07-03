#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;
using ll = long long;

struct Bit {
  ll cap;
  vector<ll> arr;
  vector<ll> tree;
 
  Bit(int size) {
    cap = size + 1;
    arr.resize(cap, 0);
    tree.resize(cap, 0);
  }
 
  void update(int i, ll x) {
    ll diff = x - arr[i];
    arr[i] = x;
    while (i < cap) {
      tree[i] += diff;
      i += i & -i;
    }
  }
  ll ask(int i, int j) const {
    if (i > j) return 0;
    return ask(j) - ask(i - 1);
  }
  ll ask(int i) const {
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

  int N, Q; cin >> N >> Q;
  vector<ll> v(N+1);
  Bit T(N);

  cin >> v[1];
  for (int i = 2; i <= N; ++i) {
    cin >> v[i];
    T.update(i-1, v[i-1] > v[i]);
  }
  for (int i = 0; i < Q; ++i) {
    int O, L, R; cin >> O >> L >> R;
    if (O == 1) {
      if (T.ask(L, R-1) == 0) cout << "CS204\n";
      else cout << "HSS090\n";
    }
    else {
      swap(v[L], v[R]);
      if (L != 1) T.update(L-1, v[L-1] > v[L]);
      if (L+1 != N+1) T.update(L, v[L] > v[L+1]);
      if (R-1 != 0) T.update(R-1, v[R-1] > v[R]);
      if (R != N) T.update(R, v[R] > v[R+1]);
    }
  }

}