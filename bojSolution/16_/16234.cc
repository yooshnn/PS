#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, L, R;
int board[52][52];
bool dup[52][52];
int bfsDir[2][4] = { {0, -1, 0, 1}, {1, 0, -1, 0} };

queue<pair<vector<pii>, int>> Q;

bool bfs(int ir, int ic) {
    vector<pii> unite; int popu = 0;

    queue<pii> que;
    dup[ir][ic] = true;

    que.push({ ir, ic });
    while (!que.empty()) {
        int cr, cc; tie(cr, cc) = que.front(); que.pop();

        unite.push_back({ cr, cc });
        popu += board[cr][cc];

        for (int i = 0; i < 4; ++i) {
            int nr = cr + bfsDir[0][i], nc = cc + bfsDir[1][i];
            int diff = abs(board[nr][nc] - board[cr][cc]);

            if (!dup[nr][nc] && L <= diff && diff <= R) {
                dup[nr][nc] = true;
                que.push({ nr, nc });
            }
        }
    }

    if (unite.size() == 1) return false;
    Q.push({ unite, popu / unite.size() });
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    fill(&board[0][0], &board[0][0] + 52 * 52, -20000);

    cin >> N >> L >> R;
    for (int r = 1; r <= N; ++r) for (int c = 1; c <= N; ++c) cin >> board[r][c];

    int res = 0;
    while (1) {
        fill(&dup[0][0], &dup[0][0] + 52 * 52, false);
        bool go = false;
        for (int r = 1; r <= N; ++r) for (int c = 1; c <= N; ++c) {
            if (!dup[r][c]) go = max(go, bfs(r, c));
        }
        if (!go) break;
        res += 1;
        while (!Q.empty()) {
            pair<vector<pii>, int> cur = Q.front(); Q.pop();
            for (pii i : cur.first) board[i.first][i.second] = cur.second;
        }
    }
    cout << res;
}