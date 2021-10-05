#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")

#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;

const int dir4[2][4] = { {0, -1, 0, 1}, {1, 0, -1, 0} };

int
  R, C,
  board[1510][1510],
  dp[1510][1510], dpbf[1510][1510], dprf[1510][1510],
  res = 10000, DSZ;

vector<pii>
  _bf, _rf;
int dup[1510][1510], dup2[1510][1510];

void init(), calc_dpr(), solve();
bool dfs(int, int, int, int);
bool oob(int r, int c) { return r<1||c<1||r>R||c>C||board[r][c]; }

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  init();

  dfs(1, 1, 3, 1);
  dfs(1, 1, 0, -1);

  calc_dpr();
  solve();

  /*
  cout << "  \n";
  for (int r = 1; r <= R; ++r) {
    for (int c = 1; c <= C; ++c) {
      char t = board[r][c] ? '#' : '.';
      bool a = false, b = false;
      for (auto [y, x] : _bf) a |= (y==r && x == c);
      for (auto [y, x] : _rf) b |= (y==r && x == c);
      if (a && b) t = '@';
      else if (a) t = '1';
      else if (b) t = '2';
      cout << t;
    }
    cout << endl;
  }
  */

  sad;
}

void init() {
  cin >> C >> R;

  char t;
  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    cin >> t;
    board[r][c] = (t == '#');
  }
  board[1][1] = 1;
  board[R][C] = 1;
  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    dp[r][c] = dp[r-1][c] + dp[r][c-1] - dp[r-1][c-1];
    dp[r][c] += board[r][c];
  }
  board[1][1] = 0;
  board[R][C] = 0;
}

bool dfs(int r, int c, int d, int w) {
  if (oob(r, c) || dup[r][c] == w+2) return false;

  vector<pii> &v = (w==1 ? _bf : _rf);

  v.push_back({r, c}), dup[r][c] = w+2;

  if (r == R && c == C) return true;

  for (int i = 1; i < 4; ++i) {
    int e = (d+6+w*i) & 3;
    if (dfs(r + dir4[0][e], c + dir4[1][e], e, w)) return true;
  }

  v.pop_back();
  return false;
}

void calc_dpr() {
  for (auto [r, c] : _bf) dup2[r][c] ^= 1;
  for (auto [r, c] : _rf) dup2[r][c] ^= 2;

  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    dpbf[r][c] = dpbf[r-1][c] + dpbf[r][c-1] - dpbf[r-1][c-1];
    dpbf[r][c] += (dup2[r][c] & 1);

    dprf[r][c] = dprf[r-1][c] + dprf[r][c-1] - dprf[r-1][c-1];
    dprf[r][c] += ((dup2[r][c] >> 1) & 1);
  }
}

void solve() {
  int X = 10000, Y, Z;

  auto check = [&](int r, int c, int w) -> bool {
    bool ret = true;
    ret &= ((dpbf[r+w][c+w] - dpbf[r-1][c+w] - dpbf[r+w][c-1] + dpbf[r-1][c-1]) != 0);
    ret &= ((dprf[r+w][c+w] - dprf[r-1][c+w] - dprf[r+w][c-1] + dprf[r-1][c-1]) != 0);
    return ret;
  };
  auto check2 = [&](int r, int c, int w) -> bool {
    return ((dp[r+w][c+w] - dp[r-1][c+w] - dp[r+w][c-1] + dp[r-1][c-1]) == 0);
  };

  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    int lp = 1, rp = min({X, R - r + 1, C - c + 1}), m;
    while (lp <= rp) {
      m = (lp + rp)/2;
      if (check(r, c, m-1)) {
        if (check2(r, c, m-1) && X > m) X = m, Y = c, Z = r;
        rp = m-1;
      } 
      else lp = m+1;
      if (lp >= X) break;
    }
    // cout << " @ " << r << ", " << c << " : " << m << endl;
  }

  if (X == 10000) cout << "Impossible";
  else cout << X << " " << Y << " " << Z;
}

/*
void calc_dpr() {
  for (int i = 1; ; ) {
    bool esc = false;
    int r = 1 + i/2, c = 1 + i/2, u, v;

    if (c > C || r <= R) while (r+1 <= R && c-1 >= 1) r++, c--;
    else while (r-1 >= R && c+1 <= C) r--, c++;
    if (r+1 <= R) u = r+1, v = c; else u = r, v = c+1;

    if (r == R && c == C) esc = true;

    dpbf[i].push_back(0), dprf[i].push_back(0);
    while (r >= 1 && c <= C) {
      dpbf[i].push_back(dpbf[i].back() + (dup[r][c]&1));
      dprf[i].push_back(dprf[i].back() + ((dup[r][c]>>1)&1));
      r--, c++;
    }
    if (dpbf[i].size() == 1) { DSZ = i, dpbf[i].pop_back(), dprf[i].pop_back(); break; }
    if (esc) { DSZ = i; break; }
    i += 1;

    r = u, c = v;
    if (r == R && c == C) esc = true;

    dpbf[i].push_back(0), dprf[i].push_back(0);
    while (r >= 1 && c <= C) {
      dpbf[i].push_back(dpbf[i].back() + (dup[r][c]&1));
      dprf[i].push_back(dprf[i].back() + ((dup[r][c]>>1)&1));
      r--, c++;
    }
    if (dpbf[i].size() == 1) { DSZ = i, dpbf[i].pop_back(), dprf[i].pop_back(); break; }
    if (esc) { DSZ = i; break; }
    i += 1;
  }
}

void solve() {
  int cc, rr;
  for (int i = 2; i < DSZ; ++i) {
    int
      lp = lower_bound(all(dpbf[i]), 1) - dpbf[i].begin(),
      rp = upper_bound(all(dprf[i]), 0) - dprf[i].begin();
    int
      r0 = i - rp + 1 - (i <= R ? 0 : i - R),
      r1 = i - lp + 1 - (i <= R ? 0 : i - R),
      c0 = lp + (i <= R ? 0 : i - R),
      c1;
    if (r0 > r1) swap(r0, r1);
    c1 = c0 + r1 - r0;
    if (c0 > c1) swap(c0, c1);

    cout << "@ " << lp << " " << rp << endl;
    cout << "[ " << r0 << " " << c0 << " " << r1 << " " << c1 << " ]\n";
    for (int r = 1; r <= R; ++r) {
      for (int c = 1; c <= C; ++c) {
        char t = board[r][c] ? '#' : '.';
        if (r0 <= r && r <= r1 && c0 <= c && c <= c1) t = board[r][c] ? '@' : '~';
        cout << t;
      }
      cout << "\n";
    }
    cout << endl;


    if (dp[r1][c1] - dp[r1][c0-1] - dp[r0-1][c1] + dp[r0-1][c0-1] == 0) {
      if (res > r1 - r0 + 1) {
        res = r1 - r0 + 1;
        cc = c0;
        rr = r0;
      }
    }
  }
}
*/