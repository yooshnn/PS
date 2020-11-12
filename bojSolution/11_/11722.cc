#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
inline int input() { int num = 0, ch; while ((ch = getchar()) > 47) { num = num * 10 + (ch & 15); } return num; }

int n;
int s[1001];
int dp[1001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> s[i];

	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (s[i] < s[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	//for (int i = 1; i <= n; ++i) cout << dp[i] << " "; cout << "\n";

	cout << *max_element(dp, dp+1001) + 1;
}