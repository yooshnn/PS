#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tup; // r, c, sz

int R, C, res;
bool dup[8][8];
int board[8][8];
int dir4[2][4]{ {0, -1, 0, 1}, {1, 0, -1, 0} };

int popIt(int br, int bc) {
    memset(&dup[0][0], false, sizeof(dup));

    int ret = 1;
    queue<pii> que; dup[br][bc] = true;
    for (que.push({ br, bc }); !que.empty(); que.pop()) {
        int cr, cc; cr = que.front().first, cc = que.front().second;
        for (int i = 0; i < 4; ++i) {
            int nr = cr + dir4[0][i], nc = cc + dir4[1][i];
            if (nr == -1 || nc == -1 || nr == R || nc == C || dup[nr][nc] || board[nr][nc] != board[cr][cc]) continue;
            ret++;
            dup[nr][nc] = true;
            que.push({ nr, nc });
        }
    }
    for (register int r = 0; r < R; ++r) for (register int c = 0; c < C; ++c) if (dup[r][c]) board[r][c] = 0;

    for (register int r = R - 2; r >= 0; --r) for (register int c = 0; c < C; ++c) {
        register int tr = r;
        while (tr <= R - 2 && board[tr + 1][c] == 0) {
            board[tr + 1][c] = board[tr][c];
            board[tr][c] = 0;
            tr++;
        }
    }
    return ret;
}

void game(int depth, int score) {
    if (depth == 4) return;
    int backup[8][8]; memcpy(&backup[0][0], &board[0][0], sizeof(board));

    for (register int r = 0; r < R; ++r) for (register int c = 0; c < C; ++c) {
        if (board[r][c]) {
            int req = popIt(r, c);
            res = max(res, score + req * req);
            if (depth + 1 != 4) game(depth + 1, score + req * req);
            memcpy(&board[0][0], &backup[0][0], sizeof(board));
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> C >> R;
    for (register int r = 0; r < R; ++r) for (register int c = 0; c < C; ++c) cin >> board[r][c];
    game(1, 0);

    cout << res;
}