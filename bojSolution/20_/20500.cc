#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
ll dp[1520][3];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N; N--;

    dp[1][0] = 0;
    dp[1][1] = dp[1][2] = 1;
    for (int i = 2; i <= N; ++i) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }
    cout << dp[N][1];
}