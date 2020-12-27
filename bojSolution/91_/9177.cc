#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tup;

bool solve(string& A, string& B, string& C) {
	int dp[202][202];
	memset(&dp[0][0], false, sizeof(dp));
	queue<tup> que;

	int a, b, L;
	for (que.push({ 0, 0, 0 }); !que.empty(); que.pop()) {
		tie(a, b, L) = que.front();
		
		if (L == C.size()) return true;

		if (C[L] == A[a]) {
			if (dp[a + 1][b] == 0) {
				que.push({ a + 1, b, L + 1 });
				dp[a + 1][b] = 1;
			}
		}
		if (C[L] == B[b]) {
			if (dp[a][b + 1] == 0) {
				que.push({ a, b + 1, L + 1 });
				dp[a][b + 1] = 1;
			}
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string a, b, c;
	int TEST; cin >> TEST; for (int tt = 1; tt <= TEST; ++tt) {
		cin >> a >> b >> c;
		cout << "Data set " << tt << ": " << (solve(a, b, c) ? "yes" : "no") << "\n";
	}
}