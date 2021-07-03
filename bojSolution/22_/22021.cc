#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using pii = pair<int, int>;

int M;
int board[10][10];

int ro[10], co[10], t;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> M;
  for (int r = 1; r <= 8; ++r) for (int c = 1; c <= 8; ++c) {
    cin >> board[r][c];
    board[r][c] -= M;

    ro[r] += board[r][c];
    co[c] += board[r][c];
    t += board[r][c];
  }

  // 1 spray : 15 fields
  t /= 15;

  // cout << t << endl;
  // for (int r = 1; r <= 8; ++r) cout << ro[r] << " "; cout << ";\n";
  // for (int r = 1; r <= 8; ++r) cout << co[r] << " "; cout << endl << endl;

  for (int r = 1; r <= 8; ++r) {
    for (int c = 1; c <= 8; ++c) {
      int k = (ro[r] - t + co[c] - t) / 7 - board[r][c];
      if (k == 1) cout << "+ ";
      else if (k == -1) cout << "- ";
      else cout << ". ";
    } cout << "\n";
  }

}