#include <bits/stdc++.h>
using namespace std;
#define sad cout.flush(), system("pause")
typedef pair<int, int> pii;
typedef tuple<int, int, int> tup;

int R, C;
char board[100][100];
int dup[100][100];
int dir4[2][4] {{0, -1, 0, 1}, {1, 0, -1, 0}};

bool oob(int r, int c) {
    return (r<0 || c<0 || r>=R || c>=C);
}

int bfs() {
    int ct, cr, cc, nt, nr, nc;
    priority_queue<tup, vector<tup>, greater<tup>> que;
    que.push({0, 0, 0});
    while (!que.empty()) {
        tie(ct, cr, cc) = que.top(); que.pop();
        if (cr == R-1 && cc == C-1) return ct;
        for (int i = 0; i < 4; ++i) {
            nr = cr + dir4[0][i], nc = cc + dir4[1][i];
            if (oob(nr, nc)) continue;
            nt = ct + (board[nr][nc]=='1');
            if (dup[nr][nc] <= nt) continue;
            dup[nr][nc] = nt;
            que.push({nt, nr, nc});
        }
    }
    return -1;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

    cin >> C >> R;
    for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
        cin >> board[r][c];
        dup[r][c] = 10000;
    }

    cout << bfs();
}