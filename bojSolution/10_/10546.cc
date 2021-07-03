#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;

map<string, int> cnt;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int N; cin >> N;
  for (int i = 0; i < N; ++i) {
    string s; cin >> s;
    cnt[s] += 1;
  }
  for (int i = 0; i < N-1; ++i) {
    string s; cin >> s;
    cnt[s] -= 1;
  }

  for (auto i : cnt) {
    if (i.second != 0) cout << i.first;
  }  

}