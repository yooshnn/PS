#define sad return 0
#include <bits/stdc++.h>
using namespace std;

set<int>
  pat1 = {1,2,6,10,16,22,26,30,36,40,44},
  pat2 = {11,15,19,29,33};

bool solve(int r, int c) {
  if (r > 44 && c > 44) {
    r = (r - 45) % 34, c = (c - 45) % 34;
    return (pat2.count(r) && pat2.count(c));
  }
  if (r <= 44 && c <= 44) return (pat1.count(r) && pat1.count(c));
  if (r > c) swap(r, c);
  c = (c - 45) % 34;
  return (pat1.count(r) && pat2.count(c));
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int r, c; cin >> r >> c;
  cout << (solve(r, c) ? "hs" : "sh");
  sad;
}