#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, d;
ll dp[100010], res = -1e9;
deque<int> que;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	
	dp[0] = -1e9;
	
	cin >> n >> d;
	for (ll t, i = 1; n--; ++i) {
		cin >> t;
		
		while (!que.empty() && (que.front() < i-d)) que.pop_front();
		
		dp[i] = (que.empty() ? 0LL : max(0LL, dp[que.front()])) + t;
		res = max(res, dp[i]);
		
		while (!que.empty() && (dp[que.back()] < dp[i])) que.pop_back();
		que.push_back(i);
	}
	cout << res;
}