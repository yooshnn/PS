#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;

int R, C, res;

struct Figure {
  int H, W;
  vector<vector<int>> shape;

  Figure(int h, int w, vector<vector<int>> s) : H{h}, W{w} {
    shape = s;
  }

  void go(vector<vector<int>> &f) {
    for (int r = 0; r <= R - H; ++r) {
      for (int c = 0; c <= C - W; ++c) {
        int cnt = 0, cntvf = 0, cnthf = 0;
        for (int h = 0; h < H; ++h) {
          for (int w = 0; w < W; ++w) {
            cnt += f[r+h][c+w] * shape[h][w];
            cntvf += f[r+h][c+w] * shape[H-h-1][w];
            cnthf += f[r+h][c+w] * shape[h][W-w-1];
          }
        }
        //res = max(res, cnt);
        res = max({res, cnt, cntvf, cnthf});
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  vector<Figure> fig;

  fig.push_back(Figure(
    1, 4,
    {
      {1, 1, 1, 1}
    }
  ));
  fig.push_back(Figure(
    2, 2,
    {
      {1, 1},
      {1, 1},
    }
  ));
  fig.push_back(Figure(
    3, 2,
    {
      {1, 0},
      {1, 0},
      {1, 1}
    }
  ));
  fig.push_back(Figure(
    3, 2,
    {
      {1, 0},
      {1, 1},
      {0, 1}
    }
  ));
  fig.push_back(Figure(
    2, 3,
    {
      {1, 1, 1},
      {0, 1, 0}
    }
  ));

  fig.push_back(Figure(
    4, 1,
    {
      {1},
      {1},
      {1},
      {1}
    }
  ));
  fig.push_back(Figure(
    2, 3,
    {
      {1, 1, 1},
      {1, 0, 0}
    }
  ));
  fig.push_back(Figure(
    2, 3,
    {
      {0, 1, 1},
      {1, 1, 0}
    }
  ));
  fig.push_back(Figure(
    3, 2,
    {
      {0, 1},
      {1, 1},
      {0, 1}
    }
  ));

  fig.push_back(Figure(
    3, 2,
    {
      {1, 1},
      {0, 1},
      {0, 1}
    }
  ));
  fig.push_back(Figure(
    2, 3,
    {
      {0, 1, 0},
      {1, 1, 1}
    }
  ));

  fig.push_back(Figure(
    2, 3,
    {
      {0, 0, 1},
      {1, 1, 1},
    }
  ));
  fig.push_back(Figure(
    2, 3,
    {
      {0, 1, 1},
      {1, 1, 0}
    }
  ));
  fig.push_back(Figure(
    3, 2,
    {
      {1, 0},
      {1, 1},
      {1, 0}
    }
  ));

  cin >> R >> C;

  vector<vector<int>> board(R);
  for (int r = 0; r < R; ++r) {
    board[r].resize(C);
    for (int c = 0; c < C; ++c) {
      cin >> board[r][c];
    }
  }
  for (Figure &i : fig) i.go(board);

  cout << res;
  
}