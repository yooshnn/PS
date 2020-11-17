#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline int input() { int num = 0, ch; while ((ch = getchar()) > 47) { num = num * 10 + (ch & 15); } return num; }

int honey, R, C;
char board[2010][1000];
bool dup[2010][1000];
priority_queue<int> room;
int bfsDir[2][6]{ {0, -1, -1, 0, 1, 1}, {2, 1, -1, -2, -1, 1} };

void bfs(int br, int bc) {
    int ret = 1;
    queue<pii> que;
    dup[br][bc] = true;
    for (que.push({ br, bc }); !que.empty(); que.pop()) {
        int cr, cc; tie(cr, cc) = que.front();
        for (int i = 0; i < 6; ++i) {
            int nr = cr + bfsDir[0][i], nc = cc + bfsDir[1][i];
            if (nr < 0 || nc < 0 || nr == R || nc >= 2 * C || dup[nr][nc] || board[nr][nc] == '#') continue;
            dup[nr][nc] = true;
            ret += 1;
            que.push({ nr, nc });
        }
    }
    room.push(ret);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> honey >> R >> C;
    for (int r = 0; r < R; ++r) for (int c = r % 2; c < 2 * C; c += 2) cin >> board[r][c];
    for (int r = 0; r < R; ++r) for (int c = r % 2; c < 2 * C; c += 2) if (!dup[r][c] && board[r][c] == '.') bfs(r, c);

    int res = 0;
    for (; honey > 0; room.pop()) {
        res++;
        honey -= room.top();
    }
    cout << res;
}