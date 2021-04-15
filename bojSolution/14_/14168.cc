#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll INF = 1e18;

int H, G;
vector<pll> h, g;
ll dp[1010][1010][2];

inline ll dist(pll a, pll b) {
  if (a.first == -1 || b.first == -1) return INF;
  return (b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second);
}

ll solve(int ch, int cg, int p) {
  if (dp[ch][cg][p] != INF) return dp[ch][cg][p];
  if (ch == 0 || cg < 0) return INF;

  if (p == 0) {
    dp[ch][cg][0] = min({
      solve(ch-1, cg, 0) + dist(h[ch-1], h[ch]),
      solve(ch-1, cg, 1) + dist(g[cg], h[ch])
    });
  }
  else {
    dp[ch][cg][1] = min({
      solve(ch, cg-1, 0) + dist(h[ch], g[cg]),
      solve(ch, cg-1, 1) + dist(g[cg-1], g[cg])
    });
  }
  return dp[ch][cg][p];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

  cin >> H >> G;
  h.resize(H + 1), g.resize(G + 1);

  for (int i = 1; i <= H; ++i) cin >> h[i].first >> h[i].second;
  for (int i = 1; i <= G; ++i) cin >> g[i].first >> g[i].second;

  h[0] = g[0] = {-1, -1};

  for (int i = 0; i <= H; ++i) for (int j = 0; j <= G; ++j) {
    dp[i][j][0] = dp[i][j][1] = INF;
  }
  dp[1][0][0] = 0;

  cout << solve(H, G, 0);
}