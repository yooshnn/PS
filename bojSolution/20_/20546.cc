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

   int BNPc, TTc; cin >> BNPc; TTc = BNPc;
   int BNPs, TTs; BNPs = TTs = 0;

   int stock[15]; for (int i = 1; i <= 14; ++i) cin >> stock[i];

   for (int i = 1; i <= 14; ++i) {
      // BNP
      if (BNPc >= stock[i]) {
         BNPs += (BNPc / stock[i]);
         BNPc -= stock[i] * (BNPc / stock[i]);
      }
      // TT
      if (i <= 3) continue;
      if (stock[i] > stock[i-1] && stock[i-1] > stock[i-2] && stock[i-2] > stock[i-3]) {
         if (TTs == 0) continue;
         TTc += stock[i] * TTs;
         TTs = 0;
      }
      if (stock[i] < stock[i-1] && stock[i-1] < stock[i-2] && stock[i-2] < stock[i-3]) {
         if (TTc < stock[i]) continue;
         TTs += (TTc / stock[i]);
         TTc -= stock[i] * (TTc / stock[i]);
      }
   }

   BNPc = (BNPc + stock[14] * BNPs);
   TTc = (TTc + stock[14] * TTs);

   if (BNPc == TTc) cout << "SAMESAME";
   else if (BNPc > TTc) cout << "BNP";
   else cout << "TIMING";

   return_0;
}