#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tup;


int R, C, res;
char board[50][50];
int bfsDir[2][4] = { {0, -1, 0, 1}, {1, 0, -1, 0} };

void bfs(int br, int bc) {
    queue<tup> que; que.push({ 0, br, bc });

    bool dup[50][50];
    fill(&dup[0][0], &dup[0][0] + sizeof(dup), false);
    dup[br][bc] = true;

    while (!que.empty()) {
        int ct, cr, cc; tie(ct, cr, cc) = que.front(); que.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = cr + bfsDir[0][i], nc = cc + bfsDir[1][i];
            if (nr == -1 || nc == -1 || nr == R || nc == C || board[nr][nc] == 'W' || dup[nr][nc]) continue;
            res = max(res, ct + 1);
            dup[nr][nc] = true;
            que.push({ ct + 1, nr, nc });
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> R >> C;
    for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) cin >> board[r][c];
    for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) if (board[r][c] == 'L') bfs(r, c);

    cout << res;
}