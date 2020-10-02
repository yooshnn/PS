#include <iostream>
#include <algorithm>
using namespace std;

int N;
short A[1001];
int dp[1001];
int res;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}

	for (int i = 1; i <= N; ++i) {
		dp[i] = A[i];
		for (int j = 1; j <= i; ++j) {
			if (A[i] > A[j] && dp[i] <= dp[j] + A[i]) dp[i] = dp[j] + A[i];
		}
		res = max(res, dp[i]);
	}
	cout << res;

	return 0;
}