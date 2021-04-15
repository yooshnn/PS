#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using ll = long long;
using pii = pair<int, int>;

map<pii, int> dp;
int N, card[210];

int solve(int L, int R) {
  if (L >= R) return 0;
  if (dp.find({L, R}) != dp.end()) return dp[{L, R}];

  vector<bool> nxt(210, false);
  for (int i = L, req; i <= R; ++i) {
    if (i + card[i] <= R) nxt[solve(L, i-1) ^ solve(i+card[i]+1, R)] = true;
  }

  for (int i = 0; i < 210; ++i) if (!nxt[i]) return dp[{L, R}] = i;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;

  for (int i = 1; i <= N; ++i) cin >> card[i];

  for (int i = 1, req; i <= N; ++i) {
    req = 0;
    if (i + card[i] <= N) {
      req = solve(1, i-1) ^ solve(i+card[i]+1, N);
      if (req == 0) return cout << i, 0;
    }
  }
  cout << -1;
}