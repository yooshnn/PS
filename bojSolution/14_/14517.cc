#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1000, MOD = 10007;
int len = 0;

inline int mod(ll n) {
	if (n >= 0) return n % MOD;
	return ((-n / MOD + 1) * MOD + n) % MOD;
}

int dp[MAX][MAX];

int solve(string s) {
	for (int i = 0; i < len; ++i) {
		dp[i][i] = 1;
		if (i >= 1) dp[i - 1][i] = 2 + (s[i - 1] == s[i]);
	}
	for (int i = 2; i < len; ++i) {
		for (int j = 0; j <= len - i; ++j) {
			dp[j][j + i] = mod((dp[j][j + i - 1] + dp[j + 1][j + i]) + (s[j] == s[j + i] ? 1 : -dp[j + 1][j + i - 1]));
		}
	}

	return dp[0][len - 1];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; cin >> s;

	len = s.length();
	cout << solve(s);

	return 0;
}