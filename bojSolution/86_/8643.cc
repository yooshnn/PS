#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int N;
int cost[500001][3];
int dp[500001][3];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        char temp; cin >> temp;
        cost[i][0] = (temp != 'A');
        cost[i][1] = (temp != 'B');
        cost[i][2] = (temp != 'C');
    }

    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];

    for (int i = 1; i < N; ++i) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }

    cout << min(dp[N-1][2], min(dp[N-1][0], dp[N-1][1])) << "\n";

    return 0;
}