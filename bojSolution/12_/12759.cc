#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;

int board[3][3];

int check() {
  int t = 0;
  for (int r = 0; r < 3; ++r) {
    t = 0;
    for (int c = 0; c < 3; ++c) t += board[r][c];
    if (t == 3) return 1;
    if (t == -3) return 2;
  }
  for (int r = 0; r < 3; ++r) {
    t = 0;
    for (int c = 0; c < 3; ++c) t += board[c][r];
    if (t == 3) return 1;
    if (t == -3) return 2;
  }
  t = 0;
  for (int r = 0; r < 3; ++r) t += board[r][r];
  if (t == 3) return 1;
  if (t == -3) return 2;
  t = 0;
  for (int r = 0; r < 3; ++r) t += board[r][2-r];
  if (t == 3) return 1;
  if (t == -3) return 2;
  return 0;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int turn, a, b;

  cin >> turn;
  turn = (turn==1 ? 1 : -1);

  while (cin >> a >> b) {
    board[--a][--b] = turn;
    int req = check();
    if (req != 0) return cout << req, 0;

    turn = (turn==1 ? -1 : 1);
  }

  cout << 0;

}