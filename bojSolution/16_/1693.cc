#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;

const int INF = 0x3f3f3f3f;

int n, m, res = INF;
int dp[100010][18];
vector<int> adj[100010];

int dfs(int par, int u, int c) {
	if (dp[u][c] != -1) return dp[u][c];

	int &ret = dp[u][c] = c+1;
	for (int i : adj[u]) {
		if (i == par) continue;
		int temp = INF;
		for (int x = 0; x < min(n, 17); ++x) {
			if (x != c) temp = min(temp, dfs(u, i, x));
		}
		ret += temp;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	
	cin >> n;
	for (int i = 0, u, v; i < n-1; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	memset(&dp[0][0], -1, sizeof dp);
	for (int i = 0; i < min(n, 17); ++i) {
		res = min(res, dfs(-1, 1, i));
	}

	cout << res;

	sad;
}