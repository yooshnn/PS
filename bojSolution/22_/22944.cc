#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int INF = 0x3f3f3f3f;

pii pos[12];

int N, H, D, U, res = INF;
int dup[12];

int dist(int i, int j) {
  return abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second);
}

void solve(int u, int h, int d, int c) {
  if (u == 1 && h >= 0) { res = min(res, c); return; }
  // if (u > 1) h += 1, d -= 1;
  if (h < 0) return;

  for (int v = 0; v < U+2; ++v) {
    if (u == v || dup[v]) continue;
    dup[v] = true;
    solve(v, h - max(0, dist(u, v) - d), v>1 ? D : d, c + dist(u, v));
    dup[v] = false;
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> H >> D;
  for (int r = 1; r <= N; ++r) for (int c = 1; c <= N; ++c) {
    char t; cin >> t;
    if (t == 'U') pos[1 + (++U)] = {r, c};
    else if (t == 'S') pos[0] = {r, c};
    else if (t == 'E') pos[1] = {r, c};
  }

  dup[0] = true;
  solve(0, H, 0, 0);

  cout << (res == INF ? -1 : res);

  sad;

}
