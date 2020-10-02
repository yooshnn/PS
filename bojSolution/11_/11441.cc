#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[100001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> dp[i]; dp[i] += dp[i - 1];
	}
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		int p, q; cin >> p >> q;
		cout << dp[q] - dp[p-1] << "\n";
	}
	
	return 0;
}