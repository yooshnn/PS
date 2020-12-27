#include <bits/stdc++.h>
using namespace std;

int m, S, x1, x2;

int main() {
   cin >> m >> S >> x1 >> x2;
   for (int a = 0; a < m; ++a) {
      for (int c = 0; c < m; ++c) {
         if (x1 == (a * S + c) % m && x2 == (a * x1 + c) % m) {
            cout << a << " " << c;
            return 0;
         }
      }
   }
}