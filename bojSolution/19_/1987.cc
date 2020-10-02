#include <iostream>
#include <algorithm>
using namespace std;

int R, C;
char board[21][21];
bool visit[27];

int res = 0;

void dfs(int r, int c, int x) {
    res = max(res, x);
    for (int i = 0; i < 4; ++i) {
        int nr = r, nc = c;
        if (i == 0) nr++; else if (i == 1) nr--; else if (i == 2) nc++; else nc--;
        if (nr <= 0 || nc <= 0 || nr > R || nc > C) continue;
        if (visit[board[nr][nc] - 'A']) continue;
        visit[board[nr][nc] - 'A'] = true;
        dfs(nr, nc, x + 1);
        visit[board[nr][nc] - 'A'] = false;
    }
}

int main() { 
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    
    cin >> R >> C;
    for (int i = 1; i <= R; ++i) { for (int j = 1; j <= C; ++j) {
        cin >> board[i][j];
    }}

    visit[board[1][1] - 'A'] = true;
    dfs(1, 1, 1);

    cout << res;

    return 0;
}