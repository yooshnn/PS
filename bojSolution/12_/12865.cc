#include <bits/stdc++.h>
using namespace std;

struct item {
	int w, v;
} items[100];

int N, K;
int dp[100][100000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		int w, v; cin >> w >> v;
		items[i] = { w, v };
	}

	for (int i = 0; i <= K; ++i) {
		if (items[0].w <= i) dp[0][i] = items[0].v;
	}

	for (int i = 1; i < N; ++i) {
		for (int j = 0; j <= K; ++j) {
			if (items[i].w > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[i].w] + items[i].v);
		}
	}

	cout << dp[N - 1][K];


	return 0;
}