#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, s, arr[100010], dp[100010];

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	
	cin >> n >> s;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		dp[i] = arr[i] + dp[i-1];
	}
	
	int c = 1, r;
	for (int l = 1; l <= n; ++l) {
		c = max(c, l);
		r = 2*c - l + 1;
		int q = c, w = r;
		
		while (r + 2 <= n && dp[c+1] - dp[l-1] <= s) {
			c += 1, r += 2;
			if (dp[r] - dp[c] <= s) q = c, w = r;
		}
		c = q, r = w;
		
		cout << (r<=n && dp[r]-dp[c] <= s && dp[c]-dp[l-1] <= s ? r - l + 1 : 0) << "\n";
	}

}