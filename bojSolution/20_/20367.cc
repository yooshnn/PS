#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll res;
vector<ll> stk;

ll dp[3030][3030];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N; stk.resize(N);
    for (ll& x : stk) cin >> x;

    if (N % 2 == 0) stk.push_back(0), N++;

    dp[2][0] = stk[1] * stk[2];
    dp[2][1] = stk[0] * stk[2];
    dp[2][2] = stk[0] * stk[1];

    for (int i = 4; i < N; i += 2) {
        for (int j = 0; j <= i - 2; ++j) {
            dp[i][j] = dp[i - 2][j] + stk[i - 1] * stk[i];
            dp[i][i - 1] = max(dp[i][i - 1], dp[i - 2][j] + stk[j] * stk[i]);
            dp[i][i] = max(dp[i][i], dp[i - 2][j] + stk[j] * stk[i - 1]);
        }

    }

    /*for (int i = 0; i < N; ++i) {
        cout << i << " : ";
        for (int j = 0; j < N; ++j) cout << dp[i][j] << " ";
        cout << "\n";
    }*/

    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) res = max(res, dp[i][j]);

    cout << res;

}