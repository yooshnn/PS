#include <bits/stdc++.h>
using namespace std;

int N;
int card[1002], dp[1002];

int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> card[i];
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < i; ++j) {
			dp[i] = max(dp[i], dp[j] + card[i - j]);
		}
	}
	cout << dp[N];
}