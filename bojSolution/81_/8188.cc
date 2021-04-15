#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;

vector<int> indices[1000001];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n; cin >> n;
  for (int i = 0, t; i < n; ++i) {
    cin >> t;
    indices[t].push_back(i);
  }

  int q; cin >> q;
  while (q--) {
    
    int pp = -1, res = 1, len;
    cin >> len;

    for (int i = 0, t; i < len; ++i) {
      cin >> t;
      if (res == 0) continue;
      int req = upper_bound(indices[t].begin(), indices[t].end(), pp) - indices[t].begin();
      if (req == indices[t].size()) res = 0;
      else pp = indices[t][req];
    }

    cout << (res == 1 ? "TAK" : "NIE") << "\n";
  }

}