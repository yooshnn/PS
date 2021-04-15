#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<char> alpha;
  for (char c = 'a'; c <= 'z'; ++c) {
    cout << c << c << c << c << endl;
    int a, b; cin >> a >> b;
    for (int i = 0; i < a; ++i) alpha.push_back(c);
  }

  do {
    for (int i = 0; i < 4; ++i) cout << alpha[i];
    cout << endl;
    string s;
    cin >> s;
    if (s.size() == 7) return 0;
    else cin >> s;
  } while (next_permutation(alpha.begin(), alpha.end()));
}
