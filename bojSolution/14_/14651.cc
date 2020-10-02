#include <iostream>
using namespace std;

long long dp[33334][3];
int n;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    cin >> n;

    dp[1][0] = 0; // 1자릿수 중 나머지가 0
    dp[1][1] = 1;
    dp[1][2] = 1;

    // 21+0
    // 22+2
    // 20+1
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 1000000009;
        }
    }

    cout << dp[n][0] << "\n";

    return 0;
}
