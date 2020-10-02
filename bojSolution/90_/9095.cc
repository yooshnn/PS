#include <iostream>
using namespace std;

int T, N;
int dp[11];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(0);

    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    for (int i = 3; i < 11; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    cin >> T;
    while (T-- > 0) {
        cin >> N;
        cout << dp[N - 1] << "\n";
    }

    return 0;
}