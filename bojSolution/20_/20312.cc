#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
   ios::sync_with_stdio(0); cin.tie(0);

   int N; cin >> N; vector<ll> v(N-1);
   for (ll& x : v) cin >> x;

   ll res = 0, prev = 0;
   for (ll& x : v) {
      res += (prev+1) * x;
      res %= (ll)1e9 + 7;
      prev = (prev+1) * x;
      prev %= (ll)1e9 + 7;
   }

   cout << res;

   return_0;
}