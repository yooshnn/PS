#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;

int n;
string s;
map<char, int> cnt;

char cntMaxChar = '\0';
int cntMax = 0;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> s;

  n = s.size() / 2;
  if (n == 1 && s[0] != s[1]) {
    return cout << "YES\n" << s, 0;
  }

  for (char c : s) {
    cnt[c] += 1;
    if (cnt[c] > cntMax) {
      cntMax = cnt[c];
      cntMaxChar = c;
    }
  }

  if (n == 2 && cnt.size() == 2) {
    if (cnt.begin()->second == 2) {
      return cout << "YES\n" << s, 0;
    }
  }

  if (cntMax >= 2*n-1 || (cntMax == 2*n-2 && cnt.size() == 2)) {
    return cout << "NO", 0;
  }

  cout << "YES\n";
  cnt.erase(cntMaxChar);

  for (int i = 0; i < min(n - 1, cntMax); ++i) cout << cntMaxChar;

  cout << cnt.begin()->first;
  cnt.begin()->second -= 1;
  if (cnt.begin()->second == 0) cnt.erase(cnt.begin());

  for (int i = 0; i < cntMax - min(n - 1, cntMax); ++i) cout << cntMaxChar;

  while (cnt.begin() != cnt.end()) {
    cout << cnt.begin()->first;
    cnt.begin()->second -= 1;
    if (cnt.begin()->second == 0) cnt.erase(cnt.begin());
  }
}