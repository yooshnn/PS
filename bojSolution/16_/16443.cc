#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using ll = long long;

int grundy[120][120];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

  for (int i = 0; i < 110; ++i) grundy[i][0] = grundy[0][i] = 499;

  for (int r = 1; r < 110; ++r) for (int c = 1; c < 110; ++c) {
    if (r==c) grundy[r][c] = 499;
    else {
      vector<bool> nxt(500, false);
      for (int k = 1; r - k >= 0; ++k) nxt[grundy[r-k][c]] = true;
      for (int k = 1; c - k >= 0; ++k) nxt[grundy[r][c-k]] = true;
      for (int k = 1; r - k >= 0 && c - k >= 0; ++k) nxt[grundy[r-k][c-k]] = true;
      for (int i = 0; i < 500; ++i) {
        if (!nxt[i]) {
          grundy[r][c] = i;
          break;
        }
      }
    }
  }

  /*
  x  x  x  x  
  x  x  0  1
  x  0  x  2
  x  1  2  x
  */

  ll N; cin >> N;
  ll res = 0;
  for (int i = 0; i < N; ++i) {
    ll r, c; cin >> r >> c;
    res ^= grundy[r][c];
    if (r == c) return cout << "Y", 0; // quit
  }
  if (res == 0) cout << "N";
  else cout << "Y";
  
}