#include <iostream>
using namespace std;

int dp[41][2];
int T, N;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(0);

    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;


    for (int i = 2; i <= 40; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }

    cin >> T;
    while (T-- > 0) {
        cin >> N;
        cout << dp[N][0] << " " << dp[N][1] << "\n";
    }
    return 0;
}