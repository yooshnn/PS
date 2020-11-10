#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tup;
inline int input() { int num = 0, ch; while ((ch = getchar()) > 47) { num = num * 10 + ch - '0'; } return num; }

char board[9][8][8];
int bfsDir[2][9] = { {0, -1, -1, -1, 0, 1, 1, 1, 0}, {1, 1, 0, -1, -1, -1, 0, 1, 0} };
bool dup[9][8][8];

bool bfs() {
    queue<tup> que;
    for (que.push({ 7, 0, 0 }); !que.empty(); que.pop()) {
        int cr, cc, ct; tie(cr, cc, ct) = que.front();
        if (board[ct][cr][cc] == '#') continue;
        if (ct == 8) return true;
        for (int i = 0; i < 9; ++i) {
            int nr, nc; nr = cr + bfsDir[0][i], nc = cc + bfsDir[1][i];
            if (nr < 0 || nc < 0 || nr == 8 || nc == 8 || dup[ct][nr][nc] || board[ct][nr][nc] == '#') continue;
            dup[ct][nr][nc] = true;
            que.push({ nr, nc, ct + 1 });
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    fill(&board[0][0][0], &board[0][0][0] + sizeof(board), '.');

    for (int r = 0; r < 8; ++r) for (int c = 0; c < 8; ++c) {
        cin >> board[0][r][c];
        for (int i = 1; r + i < 8; ++i) {
            board[i][r + i][c] = board[0][r][c];
        }
    }

    cout << bfs();
}