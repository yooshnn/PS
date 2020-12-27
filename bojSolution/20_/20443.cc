#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll n;
ll dp[110];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    dp[0] = 1;

    for (int i = 2; i <= 100; ++i) {
        dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2])) % MOD;
    }

    if (n % 4 == 0) {
        cout << dp[n];
    }
    else if (n % 4 == 1) {
        cout << (dp[n - 1] * n) % MOD;
    }
    else if (n % 4 == 2) {
        cout << (dp[n - 2] * ((n * (n - 1)) / 2)) % MOD;
    }
    else {
        cout << (dp[n - 3] * (n * (n - 1) * (n - 2)) / 6) % MOD;
    }

}