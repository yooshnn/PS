#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;
using ll = long long;

int calc(char a, char b) {
  if (a == 'N') {
    if (b == 'N') return 0;
    if (b == 'E') return 1;
    if (b == 'W') return -1;
  }
  if (a == 'W') {
    if (b == 'W') return 0;
    if (b == 'N') return 1;
    if (b == 'S') return -1;
  }
  if (a == 'E') {
    if (b == 'E') return 0;
    if (b == 'S') return 1;
    if (b == 'N') return -1;
  }
  if (a == 'S') {
    if (b == 'S') return 0;
    if (b == 'W') return 1;
    if (b == 'E') return -1;
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int TEST; cin >> TEST; while (TEST--) {
    string s; cin >> s;
    s.push_back(s[0]);
    int r = 0;
    for (int i = 1; i < s.size(); ++i) {
      r += calc(s[i-1], s[i]);
    }
    cout << (r == 4 ? "CW" : "CCW") << "\n";
  }

}