#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll
  R, C, res = 0;
int 
  _h, _v;

vector<ll>
  hor, ver;

int dsfind(int tar);
void dsmerge(int a, int b);
int rc2id(int r, int c) { return r*(_v) + c; }

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> R >> C >> _h >> _v;
  _h += 1, _v += 1;
  hor.resize(_h), ver.resize(_v);
  for (int i = 1; i < _h; ++i) cin >> hor[i];
  for (int i = 1; i < _v; ++i) cin >> ver[i];
  hor[0] = ver[0] = 0;
  hor.push_back(R), ver.push_back(C);

  sort(all(hor)), sort(all(ver));
  for (int i = 0; i < _h; ++i) hor[i] = hor[i+1] - hor[i];
  for (int i = 0; i < _v; ++i) ver[i] = ver[i+1] - ver[i];
  hor.pop_back(), ver.pop_back();
  sort(all(hor)), sort(all(ver));

  // cout << "_h, _v : " << _h << ", " << _v << endl;
  res = (hor[0] * (ll)(_v-1) + ver[0] * (ll)(_h-1));

  for (int hh = 1, vv = 1; hh < _h && vv < _v; ) {
    if (hor[hh] < ver[vv]) {
      res += hor[hh] * (ll)(_v - vv);
      // cout << "H : " << hor[hh] << " * " << (_v - vv) << endl;
      hh += 1;
    }
    else {
      res += ver[vv] * (ll)(_h - hh);
      // cout << "V : " << ver[vv] << " * " << (_h - hh) << endl;
      vv += 1;
    }
  }

  cout << res;
  
  sad;
}
