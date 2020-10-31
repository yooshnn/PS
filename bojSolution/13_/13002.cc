#include <bits/stdc++.h>
using namespace std;

int N, res;
int w[2002];
int dp[2002][2002];

int solve(int d, int l, int r) {
	if (dp[l][r] != 0) return dp[l][r];
	if (d == N + 1) return 0;

	int p = w[l + 1] * d + solve(d + 1, l + 1, r);
	int q = w[r - 1] * d + solve(d + 1, l, r - 1);

	return dp[l][r] = max(p, q);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> w[i];

	cout << solve(1, 0, N + 1);

	return 0;
}