#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int, int> tup;

pii init;
int R, C, ll, rr;
bool dup[1000][1000];
char board[1000][1000];

void bfs() {
    int cr, cc, l, r;

    deque<tup> que;
    for (que.push_back({ init.first, init.second, ll, rr }); !que.empty(); que.pop_front()) {
        tie(cr, cc, l, r) = que.front();
        while (cr + 1 < R && board[cr + 1][cc] == '0' && !dup[cr + 1][cc]) cr += 1;
        do {
            if (!dup[cr][cc]) que.push_front({ cr, cc, l, r }), dup[cr][cc] = true;
            if (r > 0 && cc + 1 < C && board[cr][cc + 1] == '0' && !dup[cr][cc + 1]) {
                que.push_back({ cr, cc + 1, l, r - 1 }); dup[cr][cc + 1] = true;
            }
            if (l > 0 && cc - 1 >= 0 && board[cr][cc - 1] == '0' && !dup[cr][cc - 1]) {
                que.push_back({ cr, cc - 1, l - 1, r }); dup[cr][cc - 1] = true;
            }
            cr -= 1;
        } while (cr >= 0 && board[cr][cc] == '0' && !dup[cr][cc]);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> R >> C >> ll >> rr;
    for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
        cin >> board[r][c];
        if (board[r][c] == '2') init = { r, c }, board[r][c] = '0';
    }
    bfs();

    int res = 0;
    for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) if (dup[r][c]) res++;
    /*for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (board[r][c] == '2') cout << "#";
            else {
                if (dup[r][c]) cout << "o";
                else cout << ".";
            }
        } cout << "\n";
    }*/
    cout << res;
}