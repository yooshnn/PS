#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;

pair<pii, pii> getTime() {
  string s; cin >> s;
  return {{10*(s[0]-'0')+(s[1]-'0'), 10*(s[3]-'0')+(s[4]-'0')}, {10*(s[6]-'0')+(s[7]-'0'), 10*(s[9]-'0')+(s[10]-'0')}};
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int N;
  while (cin >> N) {
    if (N == 0) break;
    vector<pair<pii, pii>> q;
    for (int i = 0; i < N; ++i) q.push_back(getTime());
    sort(q.begin(), q.end());
    bool conf = false;
    for (int i = 0; i < N-1; ++i) {
      if (q[i].second > q[i+1].first) conf = true;
    }
    cout << (conf ? "conflict" : "no conflict") << "\n";
  }

}