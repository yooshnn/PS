#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;

const int dir[2][4] = { {0, -1, 0, 1}, {1, 0, -1, 0} };

int N, res = 0, row = -1, col = -1;
char board[510][510];

inline bool oob(int r, int c) { return (r<1 || c<1 || r>N || c>N); }

int check(int ro, int co) {
  int ret = 0, temp = 0;
  bool good;

  good = false;
  for (int r = ro-1; r >= 1; --r) {
    if (board[r][co] == 'B') { good = true; break; }
    else if (board[r][co] == 'W') temp += 1;
    else {
      temp = 0;
      break;
    }
  }
  ret += temp * good;
  temp = 0;

  good = false;
  for (int r = ro+1; r <= N; ++r) {
    if (board[r][co] == 'B') { good = true; break; }
    else if (board[r][co] == 'W') temp += 1;
    else {
      temp = 0;
      break;
    }
  }
  ret += temp * good;
  temp = 0;

  good = false;
  for (int c = co-1; c >= 1; --c) {
    if (board[ro][c] == 'B') { good = true; break; }
    else if (board[ro][c] == 'W') temp += 1;
    else {
      temp = 0;
      break;
    }
  }
  ret += temp * good;
  temp = 0;

  good = false;
  for (int c = co+1; c <= N; ++c) {
    if (board[ro][c] == 'B') { good = true; break; }
    else if (board[ro][c] == 'W') temp += 1;
    else {
      temp = 0;
      break;
    }
  }
  ret += temp * good;
  temp = 0;

  good = false;
  for (int r = ro-1, c = co-1; r >= 1 && c >= 1; --r, --c) {
    if (board[r][c] == 'B') { good = true; break; }
    else if (board[r][c] == 'W') temp += 1;
    else {
      temp = 0;
      break;
    }
  }
  ret += temp * good;
  temp = 0;

  good = false;
  for (int r = ro-1, c = co+1; r >= 1 && c <= N; --r, ++c) {
    if (board[r][c] == 'B') { good = true; break; }
    else if (board[r][c] == 'W') temp += 1;
    else {
      temp = 0;
      break;
    }
  }
  ret += temp * good;
  temp = 0;

  good = false;
  for (int r = ro+1, c = co-1; r <= N && c >= 1; ++r, --c) {
    if (board[r][c] == 'B') { good = true; break; }
    else if (board[r][c] == 'W') temp += 1;
    else {
      temp = 0;
      break;
    }
  }
  ret += temp * good;
  temp = 0;

  good = false;
  for (int r = ro+1, c = co+1; r <= N && c <= N; ++r, ++c) {
    if (board[r][c] == 'B') { good = true; break; }
    else if (board[r][c] == 'W') temp += 1;
    else {
      temp = 0;
      break;
    }
  }
  ret += temp * good;
  temp = 0;

  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  
  cin >> N;

  for (int r = 1; r <= N; ++r) for (int c = 1; c <= N; ++c) {
    cin >> board[r][c];
  }

  for (int r = 1; r <= N; ++r) {
    for (int c = 1; c <= N; ++c) {
    if (board[r][c] != '.') continue;

    int req = check(r, c);
    if (req > res) {
      res = req;
      row = r-1;
      col = c-1;
    }
    }
  }

  if (res == 0) cout << "PASS";
  else cout << col << " " << row << "\n" << res;

  
  sad;
}