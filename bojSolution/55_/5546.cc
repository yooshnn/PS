#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 10000;

int N, K, res;
ll dp[110][3][2];
int pp[110];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	fill(&pp[0], &pp[0] + 110, -1);

	cin >> N >> K;
	for (int i = 0, p, q; i < K; ++i) {
		cin >> p >> q;
		pp[p] = q - 1;
	}
	
	if (pp[1] == -1) for (int i = 0; i < 3; ++i) dp[1][i][1] = 1;
	else dp[1][pp[1]][1] = 1;

	for (int d = 2; d <= N; ++d) {
		if (pp[d] != -1) {
			dp[d][pp[d]][1] = dp[d - 1][(pp[d] + 1) % 3][1] + dp[d - 1][(pp[d] + 2) % 3][1] + dp[d - 1][(pp[d] + 1) % 3][2] + dp[d - 1][(pp[d] + 2) % 3][2];
			dp[d][pp[d]][2] = dp[d - 1][pp[d]][1];

			dp[d][pp[d]][1] %= MOD;
			dp[d][pp[d]][2] %= MOD;
			continue;
		}
		for (int i = 0; i < 3; ++i) {
			dp[d][i][1] = dp[d - 1][(i + 1) % 3][1] + dp[d - 1][(i + 2) % 3][1] + dp[d - 1][(i + 1) % 3][2] + dp[d - 1][(i + 2) % 3][2];
			dp[d][i][2] = dp[d - 1][i][1];

			dp[d][i][1] %= MOD;
			dp[d][i][2] %= MOD;
		}
	}

	for (int i = 0; i < 3; ++i) for (int j = 1; j <= 2; ++j) res = (res + dp[N][i][j]) % MOD;
	cout << res;
}