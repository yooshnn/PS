#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int T, N;
	unsigned long long int dp[101]{ 0,1,1,1 };

	cin >> T;

	while (T-- > 0) {
		cin >> N;
		for (int i = 4; i <= N; ++i) {
			dp[i] = dp[i - 2] + dp[i - 3];
		}
		cout << dp[N] << "\n";
	}

	return 0;
}