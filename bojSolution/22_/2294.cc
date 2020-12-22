#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K;
ll dp[10020];
set<ll> coinset;
vector<ll> coin;

int main() {
	cin >> N >> K;
	for (ll i = 0, t; i < N; ++i) {
		cin >> t; if (t <= 10000) coinset.insert(t);
	}
	fill(&dp[1], &dp[K] + 1, 2147483647LL);
	for (ll i : coinset) coin.push_back(i);
	
	for (int i = 1; i <= K; ++i) {
		for (ll& c : coin) {
			if (c > i) break;
			if (dp[i] > dp[i - c] + 1) dp[i] = dp[i - c] + 1;
		}
	}

	cout << (dp[K] == 2147483647 ? -1 : dp[K]);
}