#include <iostream>
#include <algorithm>
using namespace std;

int res, n = 0;
int dp[500][500] = { 0, };

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            int input;
            cin >> input;
            dp[i][j] = input;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) dp[i][j] += dp[i - 1][0];
            else if (j == i) dp[i][j] += dp[i - 1][j - 1];
            else dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
            res = max(res, dp[i][j]);
        }
    }

    cout << res;
    return 0;
}