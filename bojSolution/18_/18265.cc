#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
   ios::sync_with_stdio(0); cin.tie(0);

   ll N, res; cin >> N;

   ll lp = 1, rp = 2e9, mid;
   while (lp <= rp) {
      mid = (lp + rp)/2;
      ll t = mid/3+mid/5-mid/15;

      if (mid - t >= N) rp = mid-1;
      else lp = mid+1;

      if (mid - t == N) res = mid;
   }
   cout << res;
}