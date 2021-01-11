#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;

ll res;
ll chilli[] {1, 7, 49, 343, 2401, 16807, 117649, 823543, 5764801, 40353607, 282475249, 1977326743, 13841287201, 96889010407, 678223072849};
ll b[] {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969};

int main() {
   ios::sync_with_stdio(0); cin.tie(0);

   ll n; cin >> n;
   vector<int> cnt(14, 0);

   for (int i = 13; i >= 0; --i) {
      while (n >= chilli[i]) {
         n -= chilli[i];
         cnt[i] += 1;
      }
   }

   for (int i = 13; i >= 0; --i) {
      res += cnt[i] * b[i];
   }
   cout << res;

   return_0;
}