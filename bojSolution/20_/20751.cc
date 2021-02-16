#include <bits/stdc++.h>
using namespace std;
#define sad cout.flush(), system("pause")
typedef long long ll;
typedef pair<int, int> pii;

int main() {
   ios::sync_with_stdio(0), cin.tie(0);

   int TEST; cin >> TEST; while (TEST--) {

      int r, c, y, x, d;
      cin >> r >> c >> y >> x >> d;
      if ((y-d <= 1 && x-d <= 1) || (y+d >= r && x+d >= c) || (x-d <= 1 && x+d >= c) || (y-d <= 1 && y+d >= r)) {
         cout << "Tuzik";
      }
      else {
         cout << "Barsik";
      }
      cout << "\n";
   }

}