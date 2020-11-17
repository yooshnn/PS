#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tup;

priority_queue<tup, vector<tup>, greater<tup>> waterQue;

int R, C;
bool rock[50][50], dup[50][50];
int water[50][50];
int bfsDir[2][4] = { {0, -1, 0, 1}, {1, 0, -1, 0} };

void flood(pii beaver) {
    while (!waterQue.empty()) {
        int ct, cr, cc; tie(ct, cr, cc) = waterQue.top(); waterQue.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = cr + bfsDir[0][i], nc = cc + bfsDir[1][i];
            if (nr < 0 || nc < 0 || nr == R || nc == C || rock[nr][nc] || water[nr][nc] <= ct + 1 || (nr == beaver.first && nc == beaver.second)) continue;
            water[nr][nc] = ct + 1;
            waterQue.push({ ct + 1, nr, nc });
        }
    }
}

int bfs(pii sonic, pii beaver) {
    queue<tup> que; que.push({ 0, sonic.first, sonic.second });
    while (!que.empty()) {
        int ct, cr, cc; tie(ct, cr, cc) = que.front(); que.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = cr + bfsDir[0][i], nc = cc + bfsDir[1][i];
            if (nr < 0 || nc < 0 || nr == R || nc == C || rock[nr][nc] || water[nr][nc] <= ct + 1 || dup[nr][nc]) continue;
            dup[nr][nc] = true;
            if (nr == beaver.first && nc == beaver.second) return ct + 1;
            que.push({ ct + 1, nr, nc });
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    pii sonic, beaver;

    cin >> R >> C;
    for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
        water[r][c] = 200000;
        char input; cin >> input;
        if (input == 'S') sonic = { r, c };
        else if (input == 'D') beaver = { r, c };
        else if (input == 'X') rock[r][c] = true;
        else if (input == '*') waterQue.push({ 0, r, c }), water[r][c] = 0;
    }
    flood(beaver);

    int req = bfs(sonic, beaver);
    if (req > 0) cout << req;
    else cout << "KAKTUS";
}