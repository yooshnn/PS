#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int board[1025][1025];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int c; cin >> c;
            board[i][j] = board[i - 1][j] + board[i][j - 1] - board[i - 1][j - 1] + c;
        }
    }
    cin >> k;
    while (k--) {
        int x_1, y_1, x_2, y_2; cin >> y_1 >> x_1 >> y_2 >> x_2;
        cout << board[y_2][x_2] - board[y_1 - 1][x_2] - board[y_2][x_1 - 1] + board[y_1 - 1][x_1 - 1] << "\n";
    }

    return 0;
}