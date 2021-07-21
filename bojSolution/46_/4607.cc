#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using ll = long long;

const int
  dir4[2][4] = {{0, -1, 0, 1}, {1, 0, -1, 0}},
  diag4[2][4] = {{-1, -1, 1, 1}, {1, -1, -1, 1}};

struct Slink {
  struct Block {
    int type;
    bool con[4], nev[4];

    Block(int _type = -1) {
      type = _type;
      fill(&con[0], &con[0]+4, false);
      fill(&nev[0], &nev[0]+4, false);
    }
  };

  int ROW, COL;
  Block board[22][22];

  Slink(int _ROW, int _COL) {
    ROW = _ROW, COL = _COL;
    for (int r = 1; r <= ROW; ++r) for (int c = 1; c <= COL; ++c) {
      cin >> board[r][c].type;
    }
  }

  void con(int r, int c, int dir) {
    dir %= 4;
    board[r][c].con[dir] = true;
    board[r+dir4[0][dir]][c+dir4[1][dir]].con[(dir+2)%4] = true;
  }
  void nev(int r, int c, int dir) {
    dir %= 4;
    board[r][c].nev[dir] = true;
    board[r+dir4[0][dir]][c+dir4[1][dir]].nev[(dir+2)%4] = true;
  }

  bool isCon(Block &tar, int i) {
    i %= 4;
    return tar.con[i];
  }
  bool isNev(Block &tar, int i) {
    i %= 4;
    return (tar.nev[i]);
  }

  void given() {
    for (int r = 1; r <= ROW; ++r) for (int c = 1; c <= COL; ++c) {
      // 0
      if (board[r][c].type == 0) {
        for (int i = 0; i < 4; ++i) nev(r, c, i);
      }
      // 3 adj
      if (board[r][c].type == 3) {
        for (int i = 0; i < 4; ++i) {
          if (board[r+dir4[0][i]][c+dir4[1][i]].type == 3) {
            con(r, c, i+2);
            con(r, c, i);
            con(r+dir4[0][i], c+dir4[1][i], i);
          }
        }
      }
      // 3 diag
      if (board[r][c].type == 3) {
        for (int i = 0; i < 4; ++i) {
          if (board[r+diag4[0][i]][c+diag4[1][i]].type == 3) {            
            con(r, c, i+2);
            con(r, c, i+3);
            con(r+diag4[0][i], c+diag4[1][i], i+1);
            con(r+diag4[0][i], c+diag4[1][i], i%4);
          }
        }
      }
    }
    // border
    for (int i = 0; i <= ROW + 1; ++i) {
      board[i][COL+1].nev[1] = board[i][COL+1].nev[3] = true;
      board[i][0].nev[1] = board[i][0].nev[3] = true;
    }
    for (int i = 0; i <= COL + 1; ++i) {
      board[0][i].nev[0] = board[0][i].nev[2] = true;
      board[ROW+1][i].nev[0] = board[ROW+1][i].nev[2] = true;
    }
  }
  void build() {
    for (int r = 1; r <= ROW; ++r) for (int c = 1; c <= COL; ++c) {
      int conCnt = accumulate(board[r][c].con, board[r][c].con+4, 0),
          nevCnt = accumulate(board[r][c].nev, board[r][c].nev+4, 0),
          unknown = [](Block &tar){ int ret = 0; for (int i = 0; i < 4; ++i) ret += !(tar.con[i] | tar.nev[i]); return ret; }(board[r][c]);
      //   x      
      // x 1 x  x 2 x  x 3
      //   
      if (unknown + conCnt == board[r][c].type) {
        for (int i = 0; i < 4; ++i) {
          if (!isCon(board[r][c], i) && !board[r][c].nev[i]) con(r, c, i);
        }
      }
      // reverse
      if (board[r][c].type == conCnt) {
        for (int i = 0; i < 4; ++i) {
          if (!isCon(board[r][c], i)) nev(r, c, i);
        }
      }

      //    n
      // ---+ n
      //    |
      if (conCnt >= 2) {
        for (int i = 0; i < 4; ++i) {
          if (isCon(board[r][c], i) && isCon(board[r][c], i+1)) {
            nev(r+diag4[0][i], c+diag4[1][i], i+2);
            nev(r+diag4[0][i], c+diag4[1][i], i+3);
          }
        }
      }

      // has con & where to go is clear
      for (int i = 0; i < 4; ++i) {
        if (!isCon(board[r][c], i)) continue;
        Block tar;

        // top
        // open dir0
        tar = board[r+dir4[0][(i+1)%4]][c+dir4[1][(i+1)%4]];
        if (isNev(tar, i) & isNev(tar, i+3)) {
          con(r+dir4[0][i], c+dir4[1][i], i+1);
        }
        // open dir1
        tar = board[r+dir4[0][i]][c+dir4[1][i]];
        if (isNev(board[r][c], i+1) & isNev(tar, i+1)) {
          con(r+dir4[0][(i+1)%4], c+dir4[1][(i+1)%4], i);
        }
        // open dir2
        tar = board[r+diag4[0][i]][c+diag4[1][i]];
        if (isNev(tar, i+2) & isNev(tar, i+3)) {
          con(r, c, i+1);
        }
        // bottom
        // open dir0
        tar = board[r+dir4[0][(i+3)%4]][c+dir4[1][(i+3)%4]];
        if (isNev(tar, i) & isNev(tar, i+1)) {
          con(r+dir4[0][i], c+dir4[1][i], i+3);
        }
        // open dir3
        tar = board[r+dir4[0][i]][c+dir4[1][i]];
        if (isNev(board[r][c], i+3) & isNev(tar, i+3)) {
          con(r+dir4[0][(i+3)%4], c+dir4[1][(i+3)%4], i);
        }
        // open dir2
        tar = board[r+diag4[0][(i+3)%4]][c+diag4[1][(i+3)%4]];
        if (isNev(tar, i+1) & isNev(tar, i+2)) {
          con(r, c, i+3);
        }
      }

      // is 3 and exits blocked
      if (board[r][c].type == 3) {
        for (int i = 0; i < 4; ++i) {
          if (
            isNev(board[r+diag4[0][i]][c+diag4[1][i]], i+2) &
            isNev(board[r+diag4[0][i]][c+diag4[1][i]], i+3)
          ) {
            con(r, c, i);
            con(r, c, i+1);
          }
        }
      } 
    }

    // exclusion
    for (int r = 1; r <= ROW; ++r) for (int c = 1; c <= COL; ++c) {
      // hor line
      if (isCon(board[r][c], 1) & isCon(board[r][c+1], 1)) {
        nev(r, c, 0);
        nev(r-1, c, 0);
      }
      if (isCon(board[r][c], 3) & isCon(board[r][c+1], 3)) {
        nev(r, c, 0);
        nev(r+1, c, 0);
      }
      // ver line
      if (isCon(board[r][c], 0) & isCon(board[r+1][c], 0)) {
        nev(r, c, 3);
        nev(r, c+1, 3);
      }
      if (isCon(board[r][c], 2) & isCon(board[r+1][c], 2)) {
        nev(r, c, 3);
        nev(r, c-1, 3);
      }

      // 3 and 1 diagonally adj
      if (board[r][c].type == 3) {
        for (int i = 0; i < 4; ++i) {
          if (
            board[r+diag4[0][i]][c+diag4[1][i]].type == 1 &&
            board[r+diag4[0][(i+2)%4]][c+diag4[1][(i+2)%4]].nev[i] &&
            board[r+diag4[0][(i+2)%4]][c+diag4[1][(i+2)%4]].nev[(i+1)%4]
          ) {
            nev(r+diag4[0][i], c+diag4[1][i], i);
            nev(r+diag4[0][i], c+diag4[1][i], i+1);
          }
        }
      }

      //  .   .   .
      //      x   
      //  . x . n .
      //      n 1 
      //  .   .   .
      if (board[r][c].type == 1) {
        for (int i = 0; i < 4; ++i) {
          if (
            isNev(board[r+diag4[0][i]][c+diag4[1][i]], i+2) &
            isNev(board[r+diag4[0][i]][c+diag4[1][i]], i+3)
          ) {
            nev(r, c, i);
            nev(r, c, i+1);
          }
        }
      }

      //  .   .   .
      //      x   
      //  . x .   .
      //        2 
      //  . x .   .
      //      n 
      //  .   .   .
      if (board[r][c].type == 2) {
        for (int i = 0; i < 4; ++i) {
          if (
            isNev(board[r+dir4[0][i]][c+dir4[1][i]], i+1) &
            isNev(board[r+dir4[0][(i+1)%4]][c+dir4[1][(i+1)%4]], i) &
            isNev(board[r+dir4[0][(i+1)%4]][c+dir4[1][(i+1)%4]], i+2)
          ) {
            con(r+dir4[0][(i+2)%4], c+dir4[1][(i+2)%4], i+1);
          }
        }
      }
    }
  }
  void solve() {
    given();
    for (int i = 0; i < ROW * COL * 8; ++i) build();
  }
  void print() {
    cout << "##";
    for (int i = 0; i < 3 * COL + (COL + 1); ++i) cout << "#";
    cout << "##";
    cout << "\n";

    cout << "# ";
    for (int i = 0; i < 3 * COL + (COL + 1); ++i) cout << " ";
    cout << " #";
    cout << "\n";

    cout << "# ";
    for (int c = 1; c <= COL + 1; ++c) {
      bool *bl = board[1][c-1].con, *b = board[1][c].con;

      if (!bl[1] & !b[1]) cout << " ";
      else if (bl[1] ^ b[1]) cout << "+";
      else cout << "-";

      if (c != COL + 1) cout << (b[1] ? "---" : "   ");
    }
    cout << " #";
    cout << "\n";

    for (int r = 1; r <= ROW; ++r) {
      cout << "# ";
      for (int c = 1; c <= COL + 1; ++c) {
        bool *cur = board[r][c].con;
        cout << (cur[2] ? "|" : " ");
        if (c != COL + 1) cout << " " << board[r][c].type << " ";
      }
      cout << " #";
      cout << "\n";

      cout << "# ";
      for (int c = 1; c <= COL + 1; ++c) {
        bool *bl = board[r+1][c-1].con, *b = board[r+1][c].con, *cur = board[r][c].con;
        
        string tt = " ";
        if (bl[1] ^ b[1]) tt = "+";
        if (cur[2] & b[2]) tt = "|";
        if (bl[1] & b[1]) tt = "-";
        cout << tt;

        if (c != COL + 1) cout << (b[1] ? "---" : "   ");
      }
      cout << " #";
      cout << "\n";
    }

    cout << "# ";
    for (int i = 0; i < 3 * COL + (COL + 1); ++i) cout << " ";
    cout << " #";
    cout << "\n";

    cout << "##";
    for (int i = 0; i < 3 * COL + (COL + 1); ++i) cout << "#";
    cout << "##";
    cout << "\n";
  }

};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int ROW, COL, TEST = 1;
  while (cin >> ROW >> COL) {
    if (ROW + COL == 0) break;

    cout << TEST++ << "\n";
    Slink S(ROW, COL);
    S.solve();
    S.print();
    cout.flush();
    

    // DEBUG
    // while (1) {
    //   int r, c, i; 
    //   cin >> r >> c >> i;
    //   cout << (S.board[r][c].nev[i] ? "YES" : "NO") << endl;
    // }

  }
}