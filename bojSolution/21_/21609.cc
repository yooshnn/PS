#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;

int dir4[2][4] = {{0, -1, 0, 1}, {1, 0, -1, 0}};

int N, M, res = 0;
int board[22][22];

vector<pii> group;

inline bool oob(int r, int c) {
  return r < 1 || c < 1 || r > N || c > N;
}

bool bfs() {
  group.clear();

  int rbc = 0, rbc_;
  bool dup[22][22];
  memset(dup, false, sizeof(dup));

  for (int r = 1; r <= N; ++r) for (int c = 1; c <= N; ++c) {
    if (board[r][c] < 1 || dup[r][c]) continue;
    rbc_ = 0;
    dup[r][c] = true;
    vector<pii> temp;
    queue<pii> que;
    for (que.push({r, c}); !que.empty(); que.pop()) {
      auto [cr, cc] = que.front();
      temp.push_back(que.front());
      for (int i = 0; i < 4; ++i) {
        int nr = cr + dir4[0][i], nc = cc + dir4[1][i];
        if (oob(nr, nc) || dup[nr][nc] || board[nr][nc] < 0 || (board[nr][nc] > 0 && board[nr][nc] != board[r][c])) continue;
        if (board[nr][nc] == 0) rbc_ += 1;
        que.push({nr, nc});
        dup[nr][nc] = true;
      }
    }
    if (temp.size() > group.size()) {
      group = temp;
      rbc = rbc_;
    }
    else if (temp.size() == group.size() && rbc_ >= rbc) {
      group = temp;
      rbc = rbc_;
    }
    for (pii &i : temp) {
      if (board[i.first][i.second] == 0) dup[i.first][i.second] = false;
    }
  }

  return group.size() > 1;
}

void why() {
  int rot[22][22];
  for (int r = N - 1; r > 0; --r) for (int c = N; c > 0; --c) {
    if (board[r][c] == -1) continue;
    int t = r + 1;
    while (t != N + 1 && board[t][c] == -10) {
      swap(board[t - 1][c], board[t][c]);
      t += 1;
    }
  }
  for (int r = 1; r <= N; ++r) {
    for (int c = 1; c <= N; ++c) {
      rot[r][c] = board[c][N + 1 - r];
    }
  }
  memcpy(&board, &rot, sizeof(board));
  for (int r = N - 1; r > 0; --r) for (int c = N; c > 0; --c) {
    if (board[r][c] == -1) continue;
    int t = r + 1;
    while (t != N + 1 && board[t][c] == -10) {
      swap(board[t - 1][c], board[t][c]);
      t += 1;
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> M;
  for (int r = 1; r <= N; ++r) for (int c = 1; c <= N; ++c) {
    cin >> board[r][c];
  }

  while (bfs()) {
    res += group.size() * group.size();
    for (pii &i : group) board[i.first][i.second] = -10;
    why();
  }

  cout << res;
}