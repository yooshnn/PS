#include <iostream>
using namespace std;

int T, N;
int dp[1000];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(0);

    dp[0] = 1;
    dp[1] = 3;
    dp[2] = 5;

    cin >> N;

    for (int i = 3; i < N; ++i) {
        dp[i] = (dp[i - 1] + 2 * dp[i - 2])%10007;
    }

    cout << dp[N - 1];

    return 0;
}