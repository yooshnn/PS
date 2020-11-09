#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
inline int input() { int num = 0, ch; while ((ch = getchar()) > 47) { num = num * 10 + ch - '0'; } return num; }

int N, mh;
int board[100][100];
int dup[100][100][100];
int bfsDir[2][4] = { {0, -1, 0, 1}, {1, 0, -1, 0} };
int res[100];

void bfs(int R, int C, int h) {
    queue<pii> que;
    for (que.push({ R, C }); !que.empty(); que.pop()) {
        int r, c; tie(r, c) = que.front();
        for (int i = 0; i < 4; ++i) {
            int nr = r + bfsDir[0][i], nc = c + bfsDir[1][i];
            if (nr < 0 || nc < 0 || nr == N || nc == N || dup[h - 1][nr][nc] || board[nr][nc] <= h) continue;
            dup[h - 1][nr][nc] = true;
            que.push({ nr, nc });
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    N = input();
    for (int r = 0; r < N; ++r) for (int c = 0; c < N; ++c) {
        board[r][c] = input(); mh = max(mh, board[r][c]);
    }

    for (int h = 1; h <= mh; ++h) for (int r = 0; r < N; ++r) for (int c = 0; c < N; ++c) {
        if (!dup[h - 1][r][c] && board[r][c] > h) {
            bfs(r, c, h);
            res[h - 1] += 1;
        }
    }

    cout << max(1, *max_element(res, res + mh));
}