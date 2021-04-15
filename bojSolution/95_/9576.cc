#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;

bool cmp(const pii &lhs, const pii &rhs) {
  if (lhs.second != rhs.second) return lhs.second < rhs.second;
  return lhs.first < rhs.first;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int TEST; cin >> TEST; while (TEST--) {
    int N, M, res = 0; cin >> N >> M;

    vector<pii> stu(M);
    vector<bool> dup(N+10, false);
    
    for (pii &i : stu) cin >> i.first >> i.second;
    sort(stu.begin(), stu.end(), cmp);

    for (pii &s : stu) {
      for (int i = s.first; i <= s.second; ++i) {
        if (!dup[i]) {
          dup[i] = true;
          res += 1;
          break;
        }
      }
    }

    cout << res << '\n';

  }
}