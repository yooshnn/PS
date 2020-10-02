#include <iostream>
using namespace std;

int T, N;
int dp[100001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(0);

    dp[0] = 0;
    dp[1] = 3;
    dp[2] = 7;
    dp[3] = 17;

    cin >> N;

    for (int i = 4; i <= N; ++i) {
        dp[i] = (2 * dp[i - 1] + dp[i - 2]) % 9901;
    }

    cout << dp[N];

    return 0;
}