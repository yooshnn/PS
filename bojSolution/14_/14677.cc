#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tup;

int N, res;
string med, conv = "BLD";
int dp[1520][1520];

void solve() {

	queue<tup> que;
	int l, r, t;

	for (que.push({ 0, 3 * N - 1, 0 }); !que.empty(); que.pop()) {
		tie(l, r, t) = que.front();
		res = max(res, t);
		if (t == 3 * N) return;

		if (med[l] == conv[t % 3] && !dp[l + 1][r]) {
			dp[l + 1][r] = true;
			que.push({ l + 1, r, t + 1 });
		}
		if (med[r] == conv[t % 3] && !dp[l][r - 1]) {
			dp[l][r - 1] = true;
			que.push({ l, r - 1, t + 1 });
		}
	}

}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> med;
	solve();
	cout << res;
}