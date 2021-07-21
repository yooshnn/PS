#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using pii = pair<int, int>;
using tup = tuple<int, int, int>;

const int INF = 2e8;

int R, C;
int board[12][12];
vector<pii> island[10];
int adj[10][10];

int N;
int root[10];
priority_queue<tup, vector<tup>, greater<tup>> mstEdge;

int dir4[2][4] = {{0, -1, 0, 1}, {1, 0, -1, 0}};
bool oob(int r, int c) { return r < 1 || c < 1 || r > R || c > C; }

void rd();
void numberIsland(int, int, int);
void bridge();
int dsfind(int);
void dsmerge(int, int);
int solve();

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  rd();
  numberIsland(1, 1, 0);
  bridge();
  int req = solve();
  cout << (req == 0 ? -1 : req);
}

void rd() {
  cin >> R >> C;
  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    cin >> board[r][c];
    board[r][c] *= -1;
  }
}

void numberIsland(int ro, int co, int id) {
  if (board[ro][co] < 0) {
    id += 1;
    queue<pii> que;
    board[ro][co] = id;
    for (que.push({ro, co}); !que.empty(); que.pop()) {
      auto [r, c] = que.front();
      island[id].push_back({r, c});
      for (int i = 0; i < 4; ++i) {
        int nr = r + dir4[0][i], nc = c + dir4[1][i];
        if (oob(nr, nc) || board[nr][nc] >= 0) continue;
        board[nr][nc] = id;
        que.push({nr, nc});
      }
    }
  }

  if (ro != R || co != C) {
    numberIsland(ro + (co == C), 1 + co % C, id);
  }
  else N = id;
}

void bridge() {
  fill(&adj[0][0], &adj[0][0]+10*10, INF);
  for (vector<pii> &grp : island) {
    if (grp.size() == 0) continue;
    for (pii &pos : grp) {
      auto [ro, co] = pos;
      for (int i = 0; i < 4; ++i) {
        int nr = ro, nc = co, dist = -1;
        do {
          nr += dir4[0][i], nc += dir4[1][i];
          dist += 1;
        } while (!oob(nr, nc) && board[nr][nc] == 0);
        if (oob(nr, nc) || dist <= 1 || board[ro][co] == board[nr][nc]) continue;
        adj[board[nr][nc]][board[ro][co]] = adj[board[ro][co]][board[nr][nc]] = min(
          adj[board[ro][co]][board[nr][nc]], dist
        );
      }
    }
  }
  for (int i = 1; i < N; ++i) for (int j = i+1; j <= N; ++j) {
    if (adj[i][j] != INF) mstEdge.push({adj[i][j], i, j});
  }
}

int dsfind(int tar) {
  if (tar == root[tar]) return tar;
  return root[tar] = dsfind(root[tar]);
}

void dsmerge(int a, int b) {
  a = dsfind(a), b = dsfind(b);
  if (a != b) root[a] = b;
}

int solve() {
  for (int i = 1; i <= N; ++i) root[i] = i;

  int cnt = 0, ret = 0;
  while (!mstEdge.empty()) {
    auto[w, u, v] = mstEdge.top(); mstEdge.pop();
    if (dsfind(u) == dsfind(v)) continue;
    dsmerge(u, v);
    ret += w;
    cnt += 1;
  }

  return (cnt == N-1) * ret;
}