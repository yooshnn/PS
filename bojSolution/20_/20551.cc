#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
   ios::sync_with_stdio(0); cin.tie(0);

   ll N, Q; cin >> N >> Q;
   vector<ll> v(N);
   for (ll& x : v) cin >> x;
   sort(v.begin(), v.end());

   ll t, req;
   while (Q--) {
      cin >> t;
      req = lower_bound(v.begin(), v.end(), t) - v.begin();
      if (req < v.size() && v[req] == t) cout << req << "\n";
      else cout << -1 << "\n";
   }
   
}