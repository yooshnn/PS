#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using pii = pair<int, int>;
using ll = long long;

const int dir4[2][4] = { {0, -1, 0, 1}, {1, 0, -1, 0} };

int R, C;
char board[210][210];
bool dup[210][210], item[26];
pii init, goal;

set<pii> resDup;
vector<pii> res;

bool oob(int r, int c) { return r < 1 || c < 1 || r > R || c > C; }

void flush() {
  memset(&dup[0][0], 0, sizeof(bool)*210*210);
}
bool solve() {
  bool coll[26];
  for (int i = 0; i < 26; ++i) coll[i] = item[i];

  queue<pii> que;
  dup[init.first][init.second] = true;
  for (que.push(init); !que.empty(); que.pop()) {
    if (resDup.find(que.front()) == resDup.end()) res.push_back(que.front());
    resDup.insert(que.front());
    auto [ro, co] = que.front();
    if (ro == goal.first && co == goal.second) break;

    for (int i = 0; i < 4; ++i) {
      int nr = ro + dir4[0][i], nc = co + dir4[1][i];
      if (oob(nr, nc) || dup[nr][nc] || board[nr][nc] == '#') continue;
      if ('A' <= board[nr][nc] && board[nr][nc] <= 'Z' && !item[board[nr][nc] - 'A']) continue;
      if ('a' <= board[nr][nc] && board[nr][nc] <= 'z') coll[board[nr][nc] - 'a'] = true;
      dup[nr][nc] = true;
      que.push({nr, nc});
    }
  }
  
  for (int i = 0; i < 26; ++i) item[i] |= coll[i];
  return (dup[goal.first][goal.second]);
}


int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> R >> C;
  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    cin >> board[r][c];
    if (board[r][c] == '@') init = {r, c};
    if (board[r][c] == '!') goal = {r, c};
  }

  while (1) {
    flush();
    int good = solve();
    if (good) break;
  }

  cout << res.size() << "\n";
  for (pii i : res) {
    cout << i.first << " " << i.second << "\n";
  }

}