#include <bits/stdc++.h>
using namespace std;

int len = 0;
int note[100002];
int dp[5][5][100002];

int getCost(int f, int t) {
	if (f == t) return 1;
	if (f == 0) return 2;
	if (abs(f - t) == 2) return 4;
	return 3;
}

int solve(int p, int q, int n) {
	if (dp[p][q][n] != 0) return dp[p][q][n];
	if (n == len - 1) return 0;

	int l = solve(note[n], q, n + 1) + getCost(p, note[n]);
	int r = solve(p, note[n], n + 1) + getCost(q, note[n]);

	dp[p][q][n] = min(l, r);

	return min(l, r);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (1) {
		cin >> note[len++];
		if (note[len - 1] == 0) break;
	}

	cout << solve(0, 0, 0);

	return 0;
}