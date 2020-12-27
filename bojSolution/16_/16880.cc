#include <bits/stdc++.h>
using namespace std;

int rook[4][4]{
    {0, 1, 2, 3},
    {1, 0, 3, 2},
    {2, 3, 0, 1},
    {3, 2, 1, 0}
};
int knight[3][3]{
    {0, 1, 1},
    {1, 1, 1},
    {1, 1, 0}
};
int palace[3][3]{
    {0, 1, 2},
    {1, 2, 0},
    {2, 0, 1}
};

int calc(int r, int c, char t) {
    if (t == 'R') {
        int b = 4 * ((r / 4) ^ (c / 4));
        int p, q; p = r % 4, q = c % 4;
        return b + rook[p][q];
    }
    if (t == 'B') {
        return min(r, c);
    }
    if (t == 'K') {
        if (r & 1) {
            if (1 - c & 1) {
                if (c < r) return 1;
                return 3;
            }
            return 2;
        }
        else {
            if (c & 1) {
                if (c < r) return 3;
                return 1;
            }
            return 0;
        }
    }
    if (t == 'N') {
        if (r == 0 || c == 0) return 0;
        r -= 1, c -= 1;
        if (r / 3 == c / 3) return knight[r % 3][c % 3];
        
        int t[3] { 1, 2, 0 };
        if (r > c) return t[c % 3];
        return t[r % 3];
    }
    if (t == 'P') {
        int b = 3 * ((r / 3) ^ (c / 3));
        int p, q; p = r % 3, q = c % 3;
        return b + palace[p][q];
    }
}

int dp[36][36];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int r, c; char t;
    int res = 0;
    while (n--) {
        cin >> r >> c >> t;
        res ^= calc(r, c, t);
    }
    cout << (res == 0 ? "cubelover" : "koosaga");
}