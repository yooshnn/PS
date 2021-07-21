#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;

int pileNo, maxRem, res; // res 0 : instant lose
vector<int> pile;

int calc() {
  int M = pile.size(), ret = 0;
  int dp[M];
  memset(&dp[0], 0, sizeof(int)*M);

  dp[0] = 0;

  for (int i = 1; i < M; ++i) {
    set<int> g;
    for (int k = 0, t; k <= maxRem; ++k) {
      t = i - k;
      if (t < 1) break;
      t -= pile[t];
      if (t >= 0) g.insert(dp[t]);
    }
    for (dp[i] = 0; g.find(dp[i]) != g.end(); ++dp[i]);
  }

  // cout << "DP : ";
  // for (int i = 1; i < M; ++i) {
  //   cout << dp[i] << " ";
  // } cout << endl;

  return dp[M-1];
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> pileNo >> maxRem;

  for (int i = 0; i < pileNo; ++i) {
    int sz; cin >> sz;
    pile.resize(sz + 1);
    for (int j = 1; j <= sz; ++j) cin >> pile[j];
    res ^= calc();
    //cout << "# " << calc() << endl;
  }

  if (res == 0) cout << "Bob will win.";
  else cout << "Alice can win.";
  
}