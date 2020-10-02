#include <iostream>
using namespace std;

int N;
long long dp[10000001];

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

	dp[0] = 1;
	for (int i = 1; i <= 10000000; ++i) {
		dp[i] = (dp[i - 1] + 4 + (i - 1) * 3)%45678;
	}
	cin >> N;
	cout << dp[N];

	return 0;
}
