#include <bits/stdc++.h>
#include <unordered_map>
#define sad cout.flush(), system("pause")
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;

ll hashIt(ll H, char c) {
  return (H * 131 + c) % MOD;
}

int R, C;
char board[30][30];

unordered_map<ll, int> dp;

int solve(int r1, int c1, int r2, int c2) {
  if (r1 > r2 || c1 > c2) return 0;

  ll capture = 0;
  for (int r = r1; r <= r2; ++r) {
    for (int c = c1; c <= c2; ++c) capture = hashIt(capture, board[r][c]);
    capture = hashIt(capture, '0');
  }
  if (dp.find(capture) != dp.end()) return dp[capture];

  vector<bool> g(50, false);
  for (int r = r1; r <= r2; ++r) {
    for (int c = c1; c <= c2; ++c) {
      if (board[r][c] == 'X') continue;
      int nxt = 0;
      nxt ^= (solve(r1, c1, r - 1, c - 1));
      nxt ^= (solve(r1, c + 1, r - 1, c2));
      nxt ^= (solve(r + 1, c1, r2, c - 1));
      nxt ^= (solve(r + 1, c + 1, r2, c2));
      g[nxt] = true;
    }
  }

  for (int i = 0;; ++i) {
    if (!g[i]) return dp[capture] = i;
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);


  cin >> R >> C;
  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) cin >> board[r][c];

  cout << (solve(1, 1, R, C) ? "First" : "Second");

}