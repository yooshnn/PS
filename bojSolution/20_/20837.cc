#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;

int N;
vector<int> ro, co;

int solve1() {
  int ret = N*N;
  for (int i = 1; i <= 4; ++i) {
    int r = 0, c = 0;
    for (int &j : ro) r += (j - 1 == i);
    for (int &j : co) c += (j - 1 == i);
    ret += (i) * max(r, c);
  }
  return ret;
}
int solve2() {
  int ret = 0;
  for (int r = 0; r < N; ++r) for (int c = 0; c < N; ++c) {
    ret += min(ro[r], co[c]);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  ro.resize(N), co.resize(N);

  for (int &i : ro) cin >> i;
  for (int &i : co) cin >> i;

  cout << solve1() << " " << solve2();

}