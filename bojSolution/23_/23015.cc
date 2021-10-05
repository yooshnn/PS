#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;

string solve(string s, string t) {
  int len = s.size();

  sort(all(t));
  for (int i = 0; i < len; ++i) if (t[i]==t[(i+len/2)%len]) return "IMPOSSIBLE";

  vector<char> v;
  for (char c : t) v.push_back(c);
  int p[26];
  for (int i = 0; i < 26; ++i) p[i] = lower_bound(all(v), 'a'+i) - v.begin();

  string ret = "";
  for (int i = 0; i < len; ++i) {
    ret.push_back(t[ (p[s[i]-'a'] + len/2 ) % len ]);
    p[s[i]-'a']++;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int _TEST; cin >> _TEST; for (int TEST = 1; TEST <= _TEST; ++TEST) {
    string s; cin >> s;
    cout << "Case #" << TEST << ": " << solve(s, s) << "\n";
  }

  sad;
}

