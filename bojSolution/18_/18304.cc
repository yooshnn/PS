#include <bits/stdc++.h>
#include <unordered_map>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using ll = long long;
using pii = pair<int, int>;

/*
  탐색할 A개의 wet zone
  위의 wet zone 간의 인접 여부 미리 계산
    - i 영역에 카메라를 두면 어떤 j 영역에 둘 수 없을 수 있다
*/

int N;
char board[12][12];

int riverCnt, wetlandCnt;
int root[12][12];
vector<vector<int>> wetland;
unordered_map<int, int> dp;

const int dir4[2][4] = {{0, -1, 0, 1}, {1, 0, -1, 0}};

bool oob(int r, int c) { return r < 1 || c < 1 || r > N || c > N; }
int rc2id(int r, int c) { --r; return r*10 + c; }
pii id2rc(int i) { --i; return {1 + i/10, 1 + i%10}; }
bool adj(int a, int b) { 
  auto [r, c] = id2rc(a);
  for (int i = 0; i < 4; ++i) {
    int nr = r + dir4[0][i], nc = c + dir4[1][i];
    if (!oob(nr, nc) && rc2id(nr, nc) == b) return true;
  }
  return false;
}

void traverse() {
  bool dup[12][12];
  memset(&dup[0][0], 0, sizeof(bool)*12*12);

  for (int r = 1; r <= N; ++r) for (int c = 1; c <= N; ++c) {
    if (board[r][c] != '*' || dup[r][c]) continue;
    root[r][c] = -(++riverCnt);
    queue<pii> que;
    dup[r][c] = true;
    for (que.push({r, c}); !que.empty(); que.pop()) {
      auto [ro, co] = que.front();
      root[ro][co] = -riverCnt;
      for (int i = 0; i < 4; ++i) {
        int nr = ro + dir4[0][i], nc = co + dir4[1][i];
        if (oob(nr, nc) || dup[nr][nc]) continue;
        dup[nr][nc] = true;
        if (board[nr][nc] == '*') que.push({nr, nc});
        else if (board[nr][nc] == '.') root[nr][nc] = riverCnt;
      }
    }
  }
}

void wetlandNumbering() {
  int temp[12][12];
  bool dup[12][12];
  memset(&temp[0][0], 0, sizeof(int)*12*12);
  memset(&dup[0][0], 0, sizeof(bool)*12*12);

  for (int r = 1; r <= N; ++r) for (int c = 1; c <= N; ++c) {
    if (root[r][c] < 1 || dup[r][c]) continue;
    temp[r][c] = ++wetlandCnt;

    queue<pii> que;
    dup[r][c] = true;
    for (que.push({r, c}); !que.empty(); que.pop()) {
      auto [ro, co] = que.front();
      temp[ro][co] = temp[r][c];
      for (int i = 0; i < 4; ++i) {
        int nr = ro + dir4[0][i], nc = co + dir4[1][i];
        if (oob(nr, nc) || dup[nr][nc] || root[r][c] != root[nr][nc]) continue;
        dup[nr][nc] = true;
        que.push({nr, nc});
      }
    }
  }
  
  wetland.resize(wetlandCnt + 1);
  for (int r = 1; r <= N; ++r) for (int c = 1; c <= N; ++c) {
    if (temp[r][c] > 0) {
      root[r][c] = temp[r][c];
      wetland[temp[r][c]].push_back(rc2id(r, c));
    }
  }
}

int go(vector<int> &v) {
  int sz = v.size();
  int M = (1<<sz) - 1; // 0001 ... 1111
  dp.clear();
  dp[0] = 0;
  vector<int> conn(sz, 0);

  for (int i = 0; i < sz; ++i) {
    conn[i] = 1<<i;
    for (int j = 0; j < sz; ++j) {
      if (adj(v[i], v[j])) conn[i] |= 1<<j;
    }
  }

  for (int t = 1; t <= M; ++t) {
    set<int> g;
    for (int i = 0; i < sz; ++i) {
      if (t & (1<<i)) { // deals with i-th block
        int nxt = t & (M - conn[i]);
        g.insert(dp[nxt]);
      }
    }
    for (int i = 0;; ++i) {
      if (g.find(i) == g.end()) {
        dp[t] = i;
        break;
      }
    }
  }

  return dp[M];
}

int solve() {
  int ret = 0;
  for (int i = 1; i <= wetlandCnt; ++i) {
    int req = go(wetland[i]);
    ret ^= req;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  // input
  cin >> N;
  for (int r = 1; r <= N; ++r) for (int c = 1; c <= N; ++c) {
    cin >> board[r][c];
  }

  traverse();
  wetlandNumbering();

  cout << (solve() == 0 ? "Second player will win" : "First player will win");

  /* DEBUG
  cout << "\n===== DEBUG =====\n";
  cout << "~ Wetland Group\n";
  for (int i = 1; i <= wetlandCnt; ++i) {
    cout << "# " << i << " : ";
    for (int x : wetland[i]) cout << x << " ";
    cout << endl;
  }
  
  cout << "~ Visualization\n";
  for (int r = 1; r <= N; ++r) {
    for (int c = 1; c <= N; ++c) {
      if (root[r][c] < 0) cout << setw(3) << "*";
      else if (root[r][c] == 0) cout << setw(3) << " ";
      else cout << setw(3) << root[r][c];
    } cout << endl;
  }
  /**/
  
}