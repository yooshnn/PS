#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;

int N; 
int board[1020][1020];
int cnt[120];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    int ro, co, h, w;
    cin >> ro >> co >> h >> w;
    

    for (int r = ro; r < ro + h; ++r) {
      for (int c = co; c < co + w; ++c) {
        board[r][c] = i + 1;
      }
    }
  }

  for (int r = 0; r < 1020; ++r) {
    for (int c = 0; c < 1020; ++c) {
      cnt[board[r][c]] += 1;
    }
  }

  for (int i = 1; i <= N; ++i) {
    cout << cnt[i] << '\n';
  }

}