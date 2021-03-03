#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;

int root[30];
int search(int tar) {
    if (tar == root[tar]) return tar;
    return root[tar] = search(root[tar]);
}
void merge(int a, int b) {
    a = search(a), b = search(b);
    if (a == b) return;
    root[b] = a;
}

int board[710][710];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
 
  int R, C, K; cin >> R >> C >> K;

  for (int i = 1; i <= 26; ++i) root[i] = i;

  for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
    char t; cin >> t;
    board[r][c] = 1 + t - 'A';
  }

  for (int c = 0; c < C; ++c) for (int r = 1; r < R; ++r) {
    merge(board[r-1][c], board[r][c]);
  }

  set<int> res;
  for (int i = 1; i <= K; ++i) res.insert(search(i));
  cout << res.size();
  
}