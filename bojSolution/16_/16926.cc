#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;

int R, C, rot;
int board[310][310], res[310][310];
vector<int> group[200];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  for (int r = 0; r < 310; ++r) for (int c = 0; c < 310; ++c) res[r][c] = board[r][c] = -1;

  cin >> R >> C >> rot;
  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) cin >> board[r][c];

  int pr = 1, pc = 1, dir = 0, gid = 0, p;
  while (board[pr][pc] != -1) {
    group[gid].push_back(board[pr][pc]);
    board[pr][pc] = -1;
    if (dir == 0) {
      if (board[pr][pc+1] != -1) pc += 1;
      else dir = 3, pr += 1;
    }
    else if (dir == 3) {
      if (board[pr+1][pc] != -1) pr += 1;
      else dir = 2, pc -= 1;
    }
    else if (dir == 2) {
      if (board[pr][pc-1] != -1) pc -= 1;
      else dir = 1, pr -= 1;
    }
    else if (dir == 1) {
      if (board[pr-1][pc] != -1) pr -= 1;
      else dir = 0, pc += 1, gid += 1;
    }
  }

  pr = 1, pc = 1, dir = 0, gid = 0, p = rot;
  while (group[gid].size() != 0) {
    p %= group[gid].size();
    res[pr][pc] = group[gid][p];
    if (dir == 0) {
      if (pc+1 <= C && res[pr][pc+1] == -1) pc += 1;
      else dir = 3, pr += 1;
    }
    else if (dir == 3) {
      if (pr+1 <= R && res[pr+1][pc] == -1) pr += 1;
      else dir = 2, pc -= 1;
    }
    else if (dir == 2) {
      if (pc-1 >= 1 && res[pr][pc-1] == -1) pc -= 1;
      else dir = 1, pr -= 1;
    }
    else if (dir == 1) {
      if (pr-1 >= 1 && res[pr-1][pc] == -1) pr -= 1;
      else dir = 0, pc += 1, gid += 1, p = rot - 1;
    }
    p += 1;
  }

  for (int r = 1; r <= R; ++r) {
    for (int c = 1; c <= C; ++c) {
      cout << res[r][c] << " ";
    }
    cout << "\n";
  }
  
}