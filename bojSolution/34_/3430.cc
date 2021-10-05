#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int
  N, M,
  b[1000010], res[1000010];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int TEST; cin >> TEST; while (TEST--) {
    
    set<int> pp;
    memset(&b[0], 0, sizeof b); // water was filled on (b[i])-th day
    memset(&res[0], -1, sizeof res);

    cin >> N >> M;

    for (int i = 1, t; i <= M; ++i) {
      cin >> t;
      if (res[0] != -1) continue;

      switch (t) {
        case 0: res[i] = 0, pp.insert(i); break;

        default:
        auto p = pp.lower_bound( b[t] );
        if (p == pp.end()) { res[0] = 1; break; }
        res[*p] = t;
        pp.erase(p);
        
        b[t] = i; 
      }
    }

    if (res[0] != -1) cout << "NO\n";
    else {
      cout << "YES\n";
      for (int i = 1; i <= M; ++i) {
        if (res[i] != -1) cout << res[i] << " ";
      }
      cout << "\n";
    }
  }

  sad;
  
}