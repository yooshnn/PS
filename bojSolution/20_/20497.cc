#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
char board[11][11];

int dir4[2][4]{ {0, -1, 0, 1}, {1, 0, -1, 0} };

bool bfs(pii init) {
    int br = init.first, bc = init.second;
    int cr, cc, nr, nc;
    if (board[br][bc] != '.') return false;

    int dup[11][11]; memset(&dup[0][0], 0, sizeof(dup));


    for (int dir = 1; dir <= 4; ++dir) {
        nr = br + dir4[0][dir - 1], nc = bc + dir4[1][dir - 1];
        if (nr == -1 || nc == -1 || nr == N || nc == N || board[nr][nc] != '.') continue;

        queue<pii> que; dup[nr][nc] = dir;
        for (que.push({ nr, nc }); !que.empty(); que.pop()) {
            tie(cr, cc) = que.front();
            for (int i = 0; i < 4; ++i) {
                nr = cr + dir4[0][i], nc = cc + dir4[1][i];
                if ((nr == br && nc == bc) || nr == -1 || nc == -1 || nr == N || nc == N || board[nr][nc] != '.' || dup[nr][nc] == dir) continue;
                dup[nr][nc] = dir;
                que.push({ nr, nc });
            }
        }
    }

    int r, c;
    set<int> color;
    for (r = 0; r < N; ++r) for (c = 0; c < N; ++c) {
        if (board[r][c] != '.' || (r == br && c == bc) || dup[r][c] == 0) continue;
        color.insert(dup[r][c]);
        if (color.size() > 1) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    int r, c, res = 0;
    for (r = 0; r < N; ++r) for (c = 0; c < N; ++c) cin >> board[r][c];
    for (r = 0; r < N; ++r) for (c = 0; c < N; ++c) res += bfs({ r, c });

    cout << res;
}