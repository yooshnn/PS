#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;

int N, res[1010];
pii cow[1010];
bool ex[1010];
vector<int> north, east;

void prep();

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 1, c, r; i <= N; ++i) {
    char d; cin >> d >> cow[i].second >> cow[i].first;
    (d=='N' ? north : east).push_back(i);
  }

  sort( all(north), [](int &l, int &r) -> bool {
    return cow[l].second < cow[r].second;
  });
  sort( all(east), [](int &l, int &r) -> bool {
    return cow[l].first < cow[r].first;
  });

  /*
              (r2, c1)
  (r2, c2) C -*->

              ^
              :
              N (r1, c1)
  */

  memset(res, -1, sizeof res);

  for (int &n : north) {
    for (int &e : east) {
      auto [r1, c1] = cow[n];
      auto [r2, c2] = cow[e];
      if (ex[n] || ex[e] || c1 < c2 || r1 > r2) continue;
      int ed = c1 - c2, nd = r2 - r1;
      if (ed != nd) {
        if (ed < nd) ex[n] = true, res[n] = nd;
        if (ed > nd) ex[e] = true, res[e] = ed;
      }
    }
  }

  for (int i = 1; i <= N; ++i) {
    if (res[i] != -1) cout << res[i];
    else cout << "Infinity";
    cout << "\n";
  } 

  sad;
}