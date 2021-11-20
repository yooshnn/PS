#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int cnt[27];
ll dp[27][61];

ll solve(int n, int m) {
	if (dp[n][m] != -1) return dp[n][m];
	if (n == 25) return (m <= cnt[25]);
	dp[n][m] = 0;
	
	for (int i = 0; i <= min(m, cnt[n]); ++i) {
		dp[n][m] += solve(n+1, m-i);
	}
	
	return dp[n][m];
}

int main() {
	memset(dp, -1, sizeof dp);
	
	string s; cin >> s;
	for (char &c : s) cnt[c-'a']++;
	
	ll res = 0;
	for (int j = 1; j <= s.size(); ++j) {
		for (int i = 0; i <= min(j, cnt[0]); ++i) res += solve(1, j-i);
	}
	
	cout << res;
}