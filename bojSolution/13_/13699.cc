#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[36];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    dp[0] = 1;
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    cout << dp[n];

    return 0;
}