#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;

int N, K;
char board[110][20];
int dir4[2][4] {{0, -1, 0, 1}, {1, 0, -1, 0}};

bool oob(int r, int c) {
  return (r < 0 || c < 0 || r >= N || c >= 10);
}

void solve() {
  bool dup[110][20], ret = true;
  memset(dup, false, sizeof(dup));
  queue<pii> que;

  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < 10; ++c) {
      if (board[r][c] == '0' || dup[r][c]) continue;
      
      int cnt = 1;
      dup[r][c] = true;
      queue<pii> proc;

      for (que.push({r, c}); !que.empty(); que.pop()) {
        auto [cr, cc] = que.front();

        for (int i = 0; i < 4; ++i) {
          int nr = cr + dir4[0][i], nc = cc + dir4[1][i];
          if (oob(nr, nc) || dup[nr][nc] || board[cr][cc] != board[nr][nc]) continue;
          dup[nr][nc] = true;
          que.push({nr, nc});
          proc.push({nr, nc});
          cnt += 1;
        }
      }

      if (cnt >= K) {
        ret = false;
        for (proc.push({r, c}); !proc.empty(); proc.pop()) {
          auto [cr, cc] = proc.front();
          board[cr][cc] = '0';
        }
      }
    }
  }

  for (int c = 0; c < 10; ++c) {
    int ground = N - 1;
    for (int r = N-1; r >= 0; --r) {
      if (board[r][c] != '0') {
        swap(board[r][c], board[ground][c]);
        ground -= 1;
      }
    }
  }

  if (ret) return;
  else solve();
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> K;

  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < 10; ++c) {
      cin >> board[r][c];
    }
  }

  solve();

  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < 10; ++c) {
      cout << board[r][c];
    } cout << "\n";
  }
}