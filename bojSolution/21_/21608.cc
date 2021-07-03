#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;

int N, res;
pair<int, set<int>> fav[410];
int uidToIdx[410];
int board[24][24];
int dir4[2][4] {{0, -1, 0, 1}, {1, 0, -1, 0}};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;

  for (int i = 0; i < N+1; ++i) {
    board[0][i] = board[N+1][i] = board[i][0] = board[i][N+1] = -1;
  }

  for (int i = 0; i < N*N; ++i) {
    cin >> fav[i].first;
    uidToIdx[fav[i].first] = i;
    for (int j = 0, t; j < 4; ++j) {
      cin >> t;
      fav[i].second.insert(t);
    }
  }

  for (int i = 0; i < N*N; ++i) {
    int p1 = -1, p2 = -1, t1, t2;
    pair<int, int> tar;
    for (int r = 1; r <= N; ++r) {
      for (int c = 1; c <= N; ++c) {
        if (board[r][c] != 0) continue;
        t1 = t2 = 0;
        for (int d = 0; d < 4; ++d) {
          int nxt = board[r+dir4[0][d]][c+dir4[1][d]];
          if (fav[i].second.find(nxt) != fav[i].second.end()) t1 += 1;
          if (nxt == 0) t2 += 1;
        }
        if (t1 > p1) {
          p1 = t1;
          p2 = t2;
          tar = {r, c};
        }
        else if (t1 == p1 && t2 > p2) {
          p2 = t2;
          tar = {r, c};
        }
      }
    }
    board[tar.first][tar.second] = fav[i].first;
  }

  for (int r = 1; r <= N; ++r) {
    for (int c = 1; c <= N; ++c) {
      int cnt = 0;
      for (int d = 0; d < 4; ++d) {
        int nxt = board[r+dir4[0][d]][c+dir4[1][d]];
        if (fav[uidToIdx[board[r][c]]].second.find(nxt) != fav[uidToIdx[board[r][c]]].second.end()) {
          cnt += 1;
        }
      }
      if (cnt == 1) res += 1;
      if (cnt == 2) res += 10;
      if (cnt == 3) res += 100;
      if (cnt == 4) res += 1000;
    }
  }

  cout << res;

}