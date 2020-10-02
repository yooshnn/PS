#include <iostream>
#include <algorithm>
using namespace std;

int N, A[100001], dp[100001], ans;

int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	dp[1] = A[1];
	ans = A[1];

	for (int i = 1; i <= N; ++i) {
		dp[i] = max(dp[i - 1] + A[i], A[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans;
}