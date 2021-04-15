#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;

int N;
vector<int> res;

void solve(int depth, int num) {
  if (depth == N) {
    res.push_back(num);
    return;
  }
  int cur = num;
  for (int i = (depth == 0 ? 2 : 0); i < 10; ++i) {
    bool good = true;
    for (int j = 2; j * j <= num * 10 + i; ++j) {
      if ((num * 10 + i) % j == 0) good = false;
    }
    if (good) solve(depth + 1, num * 10 + i);
  }
}

int main() {
  cin >> N;
  solve(0, 0);
  for (int i : res) cout << i << endl;
}