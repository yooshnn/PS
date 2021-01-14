#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;


int main() {
   ios::sync_with_stdio(0); cin.tie(0);

   int N; cin >> N;
   vector<int> s(N); for (int& x : s) cin >> x;

   int res = 0;
   set<int> ex;

   for (int i = 0; i < N; ++i) {
      int sum = 0;
      for (int j = i; j < N; ++j) {
         sum += s[j];
         ex.insert(s[j]);

         if (sum % (j-i+1) == 0 && ex.find(sum / (j-i+1)) != ex.end()) {
            res += 1;
         }
      }
      ex.clear();
   }

   cout << res;

   return_0;
}