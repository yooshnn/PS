#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
inline int input() { int num = 0, ch; while ((ch = getchar()) > 47) { num = num * 10 + ch - '0'; } return num; }

vector<int> graph[3][25];
bool dup[31];

void con(int p, int q, int i) {
    graph[i][p].push_back(q);
    graph[i][q].push_back(p);
}
int magic(int p, int q) {
    if (p > q) { int t = p; p = q; q = t; }
    if (p == 1 && q == 2) return 1;
    if (p == 1 && q == 4) return 2;
    if (p == 2 && q == 5) return 3;
    if (p == 3 && q == 4) return 4;
    if (p == 5 && q == 6) return 5;
    if (p == 3 && q == 7) return 6;
    if (p == 4 && q == 8) return 7;
    if (p == 5 && q == 9) return 8;
    if (p == 6 && q == 10) return 9;
    if (p == 8 && q == 9) return 10;
    if (p == 7 && q == 11) return 11;
    if (p == 8 && q == 12) return 12;
    if (p == 9 && q == 13) return 13;
    if (p == 10 && q == 14) return 14;
    if (p == 11 && q == 12) return 15;
    if (p == 13 && q == 14) return 16;
    if (p == 11 && q == 15) return 17;
    if (p == 12 && q == 16) return 18;
    if (p == 13 && q == 17) return 19;
    if (p == 14 && q == 18) return 20;
    if (p == 16 && q == 17) return 21;
    if (p == 15 && q == 19) return 22;
    if (p == 16 && q == 20) return 23;
    if (p == 17 && q == 21) return 24;
    if (p == 18 && q == 22) return 25;
    if (p == 19 && q == 20) return 26;
    if (p == 21 && q == 22) return 27;
    if (p == 20 && q == 23) return 28;
    if (p == 21 && q == 24) return 29;
    if (p == 23 && q == 24) return 30;
}

int dfs(int p, int i, int v) {
    bool go = false;
    int ret = 0;
    for (int d : graph[i][p]) {
        if (dup[magic(p, d)]) continue;
        go = true;
        dup[magic(p, d)] = true;
        ret = max(ret, dfs(d, i, v + 1));
        dup[magic(p, d)] = false;
    }
    if (!go) return v;
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int r = 0; r < 19; ++r) {
        string s; cin >> s;
        for (int c = 0; c < 31; ++c) {
            char i = s[c];
            i -= '1';
            if (i >= 0 && i <= 2) {
                if (r == 0) {
                    if (c == 15) con(1, 2, i);
                }
                else if (r == 1) {
                    if (c == 11) con(1, 4, i);
                    if (c == 19) con(2, 5, i);
                }
                else if (r == 3) {
                    if (c == 6) con(3, 4, i);
                    if (c == 24) con(5, 6, i);
                }
                else if (r == 5) {
                    if (c == 1) con(3, 7, i);
                    if (c == 11) con(4, 8, i);
                    if (c == 19) con(5, 9, i);
                    if (c == 29) con(6, 10, i);
                }
                else if (r == 6) {
                    if (c == 15) con(8, 9, i);
                }
                else if (r == 7) {
                    if (c == 1) con(7, 11, i);
                    if (c == 11) con(8, 12, i);
                    if (c == 19) con(9, 13, i);
                    if (c == 29) con(10, 14, i);
                }
                else if (r == 9) {
                    if (c == 6) con(11, 12, i);
                    if (c == 24) con(13, 14, i);
                }
                else if (r == 11) {
                    if (c == 1) con(11, 15, i);
                    if (c == 11) con(12, 16, i);
                    if (c == 19) con(13, 17, i);
                    if (c == 29) con(14, 18, i);
                }
                else if (r == 12) {
                    if (c == 15) con(16, 17, i);
                }
                else if (r == 13) {
                    if (c == 1) con(15, 19, i);
                    if (c == 11) con(16, 20, i);
                    if (c == 19) con(17, 21, i);
                    if (c == 29) con(18, 22, i);
                }
                else if (r == 15) {
                    if (c == 6) con(19, 20, i);
                    if (c == 24) con(21, 22, i);
                }
                else if (r == 17) {
                    if (c == 11) con(20, 23, i);
                    if (c == 19) con(21, 24, i);
                }
                else if (r == 18) {
                    if (c == 15) con(23, 24, i);
                }
            }
        }
    }

    int res[3]{ 0, 0, 0 };
    for (int h = 0; h <= 2; ++h) {
        for (int i = 1; i <= 24; ++i) {
            res[h] = max(res[h], dfs(i, h, 0));
        }
    }
    cout << res[0] << " " << res[1] << " " << res[2];
}