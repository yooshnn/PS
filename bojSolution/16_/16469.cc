#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tup;

int R, C;
char board[100][100];
int dup[3][100][100];
int bfsDir[2][4] = { {0, -1, 0, 1}, {1, 0, -1, 0} };

void bfs(int id, pii villain) {
    priority_queue<tup, vector<tup>, greater<tup>> que;
    que.push({ 0, villain.first, villain.second });
    dup[id][villain.first][villain.second] = 0;
    while (!que.empty()) {
        int cw, cr, cc; tie(cw, cr, cc) = que.top(); que.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = cr + bfsDir[0][i], nc = cc + bfsDir[1][i];
            if (nr < 0 || nc < 0 || nr == R || nc == C ||
                board[nr][nc] == '1' || dup[id][nr][nc] >= 0) continue;
            dup[id][nr][nc] = cw + 1;
            que.push({ cw + 1, nr, nc });
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> R >> C;
    for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
        dup[0][r][c] = dup[1][r][c] = dup[2][r][c] = -1;
        cin >> board[r][c];
    }

    for (int i = 0; i < 3; ++i) {
        int p, q; cin >> p >> q;
        bfs(i, { p - 1, q - 1 });
    }

    int res = 2147483647, cnt = 0;
    for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
        if (dup[0][r][c] >= 0 && dup[1][r][c] >= 0 && dup[2][r][c] >= 0) {
            int temp = max({ dup[0][r][c], dup[1][r][c], dup[2][r][c] });
            if (temp < res) {
                res = temp;
                cnt = 1;
            }
            else if (temp == res) {
                cnt += 1;
            }
        }
    }

    if (res == 2147483647) cout << -1;
    else {
        cout << res << "\n" << cnt;
    }

}