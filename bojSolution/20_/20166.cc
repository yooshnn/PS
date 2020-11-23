#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

int R, C, Q;
char board[10][10];
int bfsDir[2][8]{ {0, -1, -1, -1, 0, 1, 1, 1}, {1, 1, 0, -1, -1, -1, 0, 1} };
unordered_map<string, ll> m;

int dfs(string& s, int d, int r, int c) {
    if (d == s.size() - 1) return (board[r][c] == s[d]);
    if (board[r][c] != s[d]) return 0;

    int ret = 0;
    for (int i = 0; i < 8; ++i) {
        ret += dfs(s, d + 1, (R + r + bfsDir[0][i]) % R, (C + c + bfsDir[1][i]) % C);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> R >> C >> Q;
    for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) cin >> board[r][c];

    while (Q--) {
        string s; cin >> s;
        if (m.find(s) != m.end()) {
            cout << m[s] << "\n";
            continue;
        }
        ll res = 0;
        for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
            res += dfs(s, 0, r, c);
        }
        cout << res << "\n";
        m[s] = res;
    }

    return 0;
}