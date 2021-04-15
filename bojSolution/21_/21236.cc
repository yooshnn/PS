#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;
using ll = long long;

bool comfy[1010][1010];
int board[1010][1010];

int d[2][5] {{0, 1, -1, 0, 0}, {0, 0, 0, 1, -1}};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int N, res = 0; cin >> N;
  while (N--) {
    int x, y; cin >> x >> y;
    x += 1, y += 1;

    board[x][y] = 1;
    vector<bool> check(5);

    for (int i = 0; i < 5; ++i) {
      int nx = x + d[0][i], ny = y + d[1][i];
      check[i] = (board[nx][ny] == 1 && board[nx+1][ny] + board[nx-1][ny] + board[nx][ny+1] + board[nx][ny-1] == 3);
    }

    for (int i = 0; i < 5; ++i) {
      int nx = x + d[0][i], ny = y + d[1][i];
      if (!comfy[nx][ny] && check[i]) res += 1, comfy[nx][ny] = true;
      else if (comfy[nx][ny] && !check[i]) res -= 1, comfy[nx][ny] = false;
    }

    cout << res << "\n";
  }

}