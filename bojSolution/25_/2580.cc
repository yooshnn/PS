#include <iostream>
#include <algorithm>
using namespace std;

bool printed = false;
short board[10][10];

void sudoku(int depth) {
    if (depth == 81) {
        if (!printed) {
            printed = true;
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    cout << board[i][j] << " ";
                }
                cout << "\n";
            }
        }
        return;
    }
    int v = depth / 9, h = depth % 9;
    bool flag[10]{ false };
    if (board[v][h] == 0) {
        for (int i = 0; i <= 8; ++i) {
            flag[board[v][i]] = true;
            flag[board[i][h]] = true;
            flag[board[(v / 3) * 3 + i / 3][(h / 3) * 3 + i % 3]] = true;
        }
        for (int i = 1; i <= 9; ++i) {
            if (!flag[i]) {
                board[v][h] = i;
                sudoku(depth + 1);
                board[v][h] = 0;
            }
        }
    }
    else {
        sudoku(depth + 1);
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(0);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> board[i][j];
        }
    }

    sudoku(0);

    return 0;
}