#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int, int> tup;
typedef pair<int, int> pii;
inline int input() { int num = 0, ch; while ((ch = getchar()) > 47) { num = num * 10 + ch - '0'; } return num; }

int res = 100000;
int R, C, T;
pii sword{ -1, -1 };

int board[100][100];
bool dup[100][100][2];

int bfsDir[2][4] = { {0, -1, 0, 1}, {1, 0, -1, 0} };

void bfs() {
    queue<tup> que;
    dup[0][0][0] = true;
    for (que.push({ 0, 0, 0, 0 }); !que.empty(); que.pop()) {
        int cr, cc, ct, cg; tie(cr, cc, ct, cg) = que.front();
        if (cr == sword.first && cc == sword.second) cg = 1;
        if (cr == R - 1 && cc == C - 1) {
            res = min(res, ct); continue;
        }
        for (int i = 0; i < 4; ++i) {
            int nr, nc; nr = cr + bfsDir[0][i], nc = cc + bfsDir[1][i];
            if (nr < 0 || nc < 0 || nr == R || nc == C || dup[nr][nc][cg] || (board[nr][nc] == 1 && cg == 0)) continue;
            dup[nr][nc][cg] = true;
            if (ct + 1 <= T) que.push({ nr, nc, ct + 1, cg });
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    R = input(), C = input(), T = input();
    for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
        board[r][c] = input();
        if (board[r][c] == 2) {
            sword = { r, c };
            board[r][c] = 0;
        }
    }
    bfs();


    cout << (res <= T ? to_string(res) : "Fail");
}