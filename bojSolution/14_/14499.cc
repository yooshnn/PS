#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tup;
inline int input() { int num = 0, ch; while ((ch = getchar()) != ' ') { if (ch == '\n') break; else num = num * 10 + ch - '0'; } return num; }

int R, C;
int board[20][20];

struct Dice {
    int r, c;
    int call = 0;
    int side[6]{ 0, 0, 0, 0, 0, 0 };

    Dice(int _r, int _c) {
        r = _r, c = _c;
    }

    void roll(int dir) {
        if (dir == 1) {
            if (c + 1 == C) return;
            swap(side[0], side[3]);
            swap(side[2], side[5]);
            swap(side[0], side[5]);
            if (board[r][++c] == 0) board[r][c] = side[5];
            else side[5] = board[r][c], board[r][c] = 0;
        }
        else if (dir == 2) {
            if (c - 1 == -1) return;
            swap(side[0], side[2]);
            swap(side[3], side[5]);
            swap(side[0], side[5]);
            if (board[r][--c] == 0) board[r][c] = side[5];
            else side[5] = board[r][c], board[r][c] = 0;
        }
        else if (dir == 3) {
            if (r - 1 == -1) return;
            swap(side[0], side[1]);
            swap(side[1], side[4]);
            swap(side[1], side[5]);
            if (board[--r][c] == 0) board[r][c] = side[5];
            else side[5] = board[r][c], board[r][c] = 0;
        }
        else if (dir == 4) {
            if (r + 1 == R) return;
            swap(side[0], side[4]);
            swap(side[1], side[4]);
            swap(side[4], side[5]);
            if (board[++r][c] == 0) board[r][c] = side[5];
            else side[5] = board[r][c], board[r][c] = 0;
        }
        cout << side[0] << '\n';
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int dr, dc, t, Q;
    R = input(), C = input(), dr = input(), dc = input(), Q = input();
    for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) board[r][c] = input();
    Dice D(dr, dc);

    while (Q--) D.roll(input());
}