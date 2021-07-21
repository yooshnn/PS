#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;

int N, M;
map<string, set<string>> group;
map<string, string> mem;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> M;
  while (N--) {
    string groupName, memName;
    cin >> groupName;
    int tt; cin >> tt;
    while (tt--) {
      cin >> memName;
      group[groupName].insert(memName);
      mem[memName] = groupName;
    }
  }
  while (M--) {
    string s, t;
    cin >> s >> t;
    if (t == "0") {
      for (string i : group[s]) cout << i << "\n";
    }
    else {
      cout << mem[s] << "\n";
    }
  }

}