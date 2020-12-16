#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tup;

bool dup[10][10];
int bfsDir[2][4]{ {0, -1, 0, 1}, {1, 0, -1, 0} };

char board[10][10];
void bfs(tup init) {
    queue<tup> que;
    for (que.push(init); !que.empty(); que.pop()) {
        int cr, cc, ct; tie(cr, cc, ct) = que.front();
        for (int i = 0; i < 4; ++i) {
            int nr = cr + bfsDir[0][i], nc = cc + bfsDir[1][i];
            if (nr < 0 || nc < 0 || nr >= 10 || nc >= 10 || board[nr][nc] == 'R' || dup[nr][nc]) continue;
            dup[nr][nc] = true;
            if (board[nr][nc] == 'L') {
                cout << ct; return;
            }
            que.push({ nr, nc, ct + 1 });
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int r = 0; r < 10; ++r) for (int c = 0; c < 10; ++c) cin >> board[r][c];
    for (int r = 0; r < 10; ++r) for (int c = 0; c < 10; ++c) {
        if (board[r][c] == 'B') {
            bfs({ r, c, 0 });
            return 0;
        }
    }
}