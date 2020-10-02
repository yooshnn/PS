#include <iostream>
using namespace std;

unsigned long long int dp[91]{ 0, };
int N;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(0);

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;

    cin >> N;
    
    for (int i = 4; i <= N; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[N];

    return 0;
}