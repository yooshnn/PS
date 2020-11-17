#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tup;


int R, C, res;
int board[1001][1001];
int dup[1001][1001];
int bfsDir[2][4] = { {0, -1, 0, 1}, {1, 0, -1, 0} };

void bfs(int br, int bc) {
    queue<tup> que; que.push({ 0, br, bc });

    while (!que.empty()) {
        int ct, cr, cc; tie(ct, cr, cc) = que.front(); que.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = cr + bfsDir[0][i], nc = cc + bfsDir[1][i];
            if (nr == -1 || nc == -1 || nr == R || nc == C || board[nr][nc] == 0 || dup[nr][nc] >= 0) continue;
            dup[nr][nc] = ct + 1;
            que.push({ ct + 1, nr, nc });
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int rr, cc;
    cin >> R >> C;
    for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
        dup[r][c] = -1;
        cin >> board[r][c];
        if (board[r][c] == 2) rr = r, cc = c;
    }
    dup[rr][cc] = 0;
    bfs(rr, cc);

    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (dup[r][c] > 0 || (r == rr && c == cc)) cout << dup[r][c];
            else {
                if (board[r][c] == 0) cout << 0;
                else cout << -1;
            }
            cout << " ";
        } cout << "\n";
    }
}