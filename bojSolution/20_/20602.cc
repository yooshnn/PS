#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;

int
  A, B, C,
  W, H;

string img[5] = {
  "..+-+",
  "././|",
  "+-+.+",
  "|.|/.",
  "+-+.."
};

void put(vector<vector<char>> &pic, int r, int c) {
  int i;
  for (i = 2; i < 5; ++i) pic[r-4][c+i] = img[0][i];
  for (i = 1; i < 5; ++i) pic[r-3][c+i] = img[1][i];
  for (i = 0; i < 5; ++i) pic[r-2][c+i] = img[2][i];
  for (i = 0; i < 4; ++i) pic[r-1][c+i] = img[3][i];
  for (i = 0; i < 3; ++i) pic[r][c+i] = img[4][i];
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int _TEST; cin >> _TEST; while (_TEST--) {
    cin >> A >> B >> C;
    W = 2*A + 1 + 2*B;
    H = 2*C + 1 + 2*B;

    vector<vector<char>> pic(H);
    for (vector<char> &i : pic) i.resize(W, '.');

    for (int b = B-1; b >= 0; --b) {
      for (int c = 0; c < C; ++c) {
        for (int a = 0; a < A; ++a) {
          put(pic, H - 1 - b*2 - c*2, a*2 + b*2);
        }
      }
    }

    for (int h = 0; h < H; ++h) {
      for (int w = 0; w < W; ++w) {
        cout << pic[h][w];
      } cout << "\n";
    }
  }

}