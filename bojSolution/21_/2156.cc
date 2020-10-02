#include <iostream>
#include <algorithm>
using namespace std;

int a[10001];
long long int dp[10001];
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int T, N;

	cin >> T;

	for (int i = 1; i <= T; ++i) {
		cin >> N;
		a[i] = N;
	}
	dp[1] = a[1];
	dp[2] = a[1] + a[2];
	dp[3] = max(max(a[1] + a[2], a[1] + a[3]), a[2] + a[3]);
	for (int i = 4; i <= T; ++i) {
		dp[i] = max(a[i] + a[i - 1] + dp[i - 3], a[i] + dp[i - 2]);
		dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << dp[T] << "\n";

	return 0;
}