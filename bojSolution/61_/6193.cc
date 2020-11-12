#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;

int N;
int s[5001];
int dp[5001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> s[i];

	for (int i = 2; i <= N; ++i) {
		for (int j = 1; j < i; ++j) {
			if (s[j] < s[i]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	cout << *max_element(dp, dp + 5001) + 1;
}