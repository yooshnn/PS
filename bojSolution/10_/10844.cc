#include <iostream>
#include <algorithm>
using namespace std;

long long int N, res = 0;
long long int dp[101][10];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i < 10; ++i) dp[1][i] = 1;
    for (int i = 2; i <= N; ++i) {
        dp[i][0] = dp[i - 1][1];
        dp[i][9] = dp[i - 1][8];
        for (int j = 1; j <= 8; ++j) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
    }
    for (int i = 0; i < 10; ++i) {
        res += dp[N][i] % 1000000000;
    }


    cout << res % 1000000000;

    return 0;
}
