#include <bits/stdc++.h>
using namespace std;

int n, res;
int a[1001];
int dp[1001][2];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    // inc
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i]) dp[i][0] = max(dp[i][0], dp[j][0] + 1);
        }
    }
    // dec
    dp[n - 1][1] = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (a[j] < a[i]) dp[i][1] = max(dp[i][1], dp[j][1] + 1);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        //if (i - 1 < 0 || i + 1 >= n) continue;
        res = max(res, dp[i][0] + dp[i][1] + 1);
    }

    cout << res;


    return 0;
}