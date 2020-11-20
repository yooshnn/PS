#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int R, C;
char board[100][100];

int solve(pii init) {
    if (init.first < 0 || init.second < 0 || init.first == R || init.second == C) return -1;
    queue<pii> que;
    int ret = 0;
    for (que.push(init); !que.empty(); que.pop()) {
        ret++;
        int cr, cc; tie(cr, cc) = que.front();
        if (board[cr][cc] == '>') que.push({ cr, cc + 1 });
        else if (board[cr][cc] == '^') que.push({ cr - 1, cc });
        else if (board[cr][cc] == 'v') que.push({ cr + 1, cc });
        else if (board[cr][cc] == '<') que.push({ cr, cc - 1 });
        else if (board[cr][cc] == 'x') return ret;
        else return -1;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    pii duck;

    cin >> R >> C;
    for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
        cin >> board[r][c];
        if (board[r][c] == 'o') duck = { r, c };
    }
    
    char res = '!';
    int M = 2147483647, req;
    req = solve({ duck.first, duck.second + 1 });
    if (req != -1 && req < M) {
        M = req;
        res = 'E';
    }
    req = solve({ duck.first - 1, duck.second });
    if (req != -1 && req < M) {
        M = req;
        res = 'N';
    }
    req = solve({ duck.first + 1, duck.second });
    if (req != -1 && req < M) {
        M = req;
        res = 'S';
    }
    req = solve({ duck.first, duck.second - 1 });
    if (req != -1 && req < M) {
        M = req;
        res = 'W';
    }
    if (res == '!') cout << ":(";
    else {
        cout << ":)\n" << res;
    }
}