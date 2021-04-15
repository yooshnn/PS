#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;


const ll x = 11, md = 1e7 + 9;

string s;
int len, lp, rp;
ll lh, rh, xAcc = 1;

bool closed = false;

bool roll() {
  if (lp == rp) return false;
  lh = ((lh * x) + s[lp] - 'a') % md;
  rh = (((s[rp] - 'a') * xAcc) + rh) % md;
  lp += 1;
  rp -= 1;
  return lh == rh;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int TEST; cin >> TEST; while (TEST--) {

    cin >> s;
    len = s.size(), lp = 0, rp = len - 1;
    lh = 0, rh = 0, xAcc = 1;
    closed = false;
    
    int res = 0;

    while (lp < rp) {
      if (roll()) {
        res += 2;
        lh = rh = 0;
        closed = true;
        xAcc = 1;
        // cout << "[" << lp << " " << rp << "]" << endl;
      }
      else {
        xAcc = (xAcc * x) % md;
        closed = false;
      }
    }

    cout << res + !closed + (closed && lp == rp) << "\n";

  }

}