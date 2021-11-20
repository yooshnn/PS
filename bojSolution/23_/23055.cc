#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;

char board[30][30];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int N; cin >> N;

  for (int i = 1; i <= N; ++i) {
    board[1][i] = board[i][1] = board[N][i] = board[i][N] = board[i][i] = board[i][N-i+1] = '*';
  }

  for (int r = 1; r <= N; ++r) {
    for (int c = 1; c <= N; ++c) {
      cout << (board[r][c] == '*' ? '*' : ' ');
    }
    cout << "\n";
  }

  
  sad;
}
