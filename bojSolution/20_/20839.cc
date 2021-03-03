#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
 
  int X, Y, Z, x, y, z; cin >> X >> Y >> Z >> x >> y >> z;

  int A, C, E; A = C = E = 0;

  if (z == Z) E = 2;

  if (E == 2) {
    if (y == Y) C = 2;
    else if (y * 2 >= Y) C = 1;

    if (C == 2) {
      if (x == X) A = 2;
      else if (x * 2 >= X) A = 1;
    }
  }

  if (A == 2) cout << "A";
  else if (A == 1) cout << "B";
  else if (C == 2) cout << "C";
  else if (C == 1) cout << "D";
  else cout << "E";

}