#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using pii = pair<int, int>;
using rct = tuple<int, int, int>;

const int INF = 2e9;

int
    N,
    W,
    actd[1010][1010],
    dir4[2][4] {{0, -1, 0, 1}, {1, 0, -1, 0}},
    dir8[2][8] {{0, -1, -1, -1, 0, 1, 1, 1}, {1, 1, 0, -1, -1, -1, 0, 1}};
bool
    rock[1010][1010],
    dup[1010][1010];

queue<rct> que;

bool oob(int r, int c) {
  return (r < 1 || c < 1 || r > N || c > N);
}

void init() {
  cin >> N >> W;

  for (int r = 0; r <= N + 1; ++r) {
    for (int c = 0; c <= N + 1; ++c) {
      actd[r][c] = INF;
    }
  }

  actd[1][1] = actd[N][N] = 0;
}

void readData() {
  for (int i = 0; i < W; ++i) {
    int ro, co; cin >> ro >> co;
    actd[ro][co] = 0;
    que.push({ro, co, 0});
  }

  for (int r = 1; r <= N; ++r) {
    for (int c = 1; c <= N; ++c) {
      char t; cin >> t;
      rock[r][c] = (t == '1' ? true : false);
    }
  }
}

void calcActd() {
  for (; !que.empty(); que.pop()) {
    auto [ro, co, t] = que.front();
    t += 1;

    for (int i = 0; i < 4; ++i) {
      int nr = ro + dir4[0][i], nc = co + dir4[1][i];
      if (oob(nr, nc) || actd[nr][nc] <= t) continue;
      actd[nr][nc] = t;
      que.push({nr, nc, t});
    }
  }
}

void solve() {
  bool ok;
  int lp = 0, rp = 2200, mid, res = -1;

  while (lp <= rp) {
    ok = false;
    mid = (lp + rp) / 2;
    for (int r = 0; r <= N + 1; ++r) {
      for (int c = 0; c <= N + 1; ++c) {
        dup[r][c] = false;
      }
    }

    queue<pii> que;
    for (que.push({1, 1}); !que.empty(); que.pop()) {
      auto [ro, co] = que.front();
      if (ro == N && co == N) {
        ok = true;
        break;
      }
      for (int i = 0; i < 8; ++i) {
        int nr = ro + dir8[0][i], nc = co + dir8[1][i];
        if (oob(nr, nc) || dup[nr][nc]) continue;
        if (rock[nr][nc] == false) continue;
        if ((nr != N || nc != N) && actd[nr][nc] > mid) continue;
        dup[nr][nc] = true;
        que.push({nr, nc});
      }
    }

    if (ok) {
      rp = mid - 1;
      res = mid;
    }
    else {
      lp = mid + 1;
    }
  }

  cout << res;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);


  init();
  readData();
  calcActd();
  solve();

}