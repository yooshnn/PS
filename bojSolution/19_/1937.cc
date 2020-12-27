#include <bits/stdc++.h>
using namespace std;

int N, res;
int board[500][500];
int dp[500][500];

int solve(int r, int c) {
    if (dp[r][c] != -1) return dp[r][c];

    bool f = false;
    if (r - 1 >= 0 && board[r - 1][c] < board[r][c]) {
        dp[r][c] = max(dp[r][c], solve(r - 1, c) + 1);
        f = true;
    }
    if (c - 1 >= 0 && board[r][c - 1] < board[r][c]) {
        dp[r][c] = max(dp[r][c], solve(r, c - 1) + 1);
        f = true;
    }
    if (r + 1 < N && board[r + 1][c] < board[r][c]) {
        dp[r][c] = max(dp[r][c], solve(r + 1, c) + 1);
        f = true;
    }
    if (c + 1 < N && board[r][c + 1] < board[r][c]) {
        dp[r][c] = max(dp[r][c], solve(r, c + 1) + 1);
        f = true;
    }
    if (!f) dp[r][c] = 1;

    return dp[r][c];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    fill(&dp[0][0], &dp[0][0] + 250000, -1);

    cin >> N;
    for (int r = 0; r < N; ++r) for (int c = 0; c < N; ++c) cin >> board[r][c];

    for (int r = 0; r < N; ++r) for (int c = 0; c < N; ++c) res = max(res, solve(r, c));

    /*for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cout << dp[r][c] << " ";
        } cout << "\n";
    }*/

    cout << res;
}