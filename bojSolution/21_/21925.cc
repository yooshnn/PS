#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;

int N, t, res;
vector<int> s;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> t;
    s.push_back(t);
    if (s.size() >= 2 && s.size()%2 == 0 && s[0] == s[s.size()-1]) {
      bool good = true;
      for (int j = 0; good && j < s.size()/2; ++j) {
        if (s[j] != s[s.size()-1-j]) good = false;
      }
      if (good) {
        s.clear();
        res += 1;
      }
    }
  }
  if (s.empty()) cout << res;
  else cout << -1;

}