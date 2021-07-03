#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using pii = pair<int, int>;
using tup = tuple<int, int, int>;

const int INF = 2e8;
const int dir4[2][4] = {{0, -1, 0, 1}, {1, 0, -1, 0}};

int N, S;
char board[810][810];
int beeArrival[810][810];
int dup[810][810];

pii bear, home;
vector<pii> bee;

bool oob(int r, int c) { return r < 1 || c < 1 || r > N || c > N; }

void beeCalc() {
  queue<pii> que;
  for (pii &i : bee) que.push(i);
  for (; !que.empty(); que.pop()) {
    auto[ro, co] = que.front();
    for (int i = 0; i < 4; ++i) {
      int nr = ro + dir4[0][i], nc = co + dir4[1][i];
      if (oob(nr, nc) || board[nr][nc] != 'G' ||
        beeArrival[nr][nc] <= beeArrival[ro][co] + 1) continue;
      beeArrival[nr][nc] = beeArrival[ro][co] + 1;
      que.push({nr, nc});
    }
  }
}

bool bfs(int _t) {
  if (_t >= beeArrival[bear.first][bear.second]) return false;

  for (int r = 0; r < 810; ++r) for (int c = 0; c < 810; ++c) dup[r][c] = INF;
  dup[bear.first][bear.second] = _t;

  queue<tup> que;
  for (que.push({bear.first, bear.second, S}); !que.empty(); que.pop()) {
    auto[ro, co, s] = que.front();
    s -= 1;
    if (board[ro][co] == 'D') return true;
    for (int i = 0; i < 4; ++i) {
      int nr = ro + dir4[0][i], nc = co + dir4[1][i];
      if (oob(nr, nc) || board[nr][nc] == 'T') continue;
      if (dup[ro][co] + (s == 0) >= dup[nr][nc]) continue;
      if (dup[ro][co] + (s == 0) >= beeArrival[nr][nc]) continue;
      dup[nr][nc] = dup[ro][co] + (s == 0);
      que.push({nr, nc, (s == 0 ? S : s)});
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  for (int r = 0; r < 810; ++r) for (int c = 0; c < 810; ++c) {
    beeArrival[r][c] = INF;
  }

  cin >> N >> S;
  for (int r = 1; r <= N; ++r) for (int c = 1; c <= N; ++c) {
    cin >> board[r][c];
    if (board[r][c] == 'H') bee.push_back({r, c}), beeArrival[r][c] = 0;
    if (board[r][c] == 'M') bear = {r, c}, board[r][c] = 'G';
    if (board[r][c] == 'D') home = {r, c};
  }

  beeCalc();

  int lp = 0, rp = 1000000, mid, res = -1;
  while (lp <= rp) {
    mid = (lp + rp) / 2;
    if (bfs(mid)) {
      res = max(res, mid);
      lp = mid + 1;
    }
    else {
      rp = mid - 1;
    }
  }

  cout << res;

  /*
  for (int r = 1; r <= N; ++r) {
    for (int c = 1; c <= N; ++c) {
      if (beeArrival[r][c] == INF) cout << setw(4) << "_";
      else cout << setw(4) << beeArrival[r][c];
    } cout << endl;
  }
  */

}