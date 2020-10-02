#include <bits/stdc++.h>
using namespace std;

struct w {
	int a, b;
} wire[100];

bool cmp(const w& p, const w& q) {
	return p.a < q.a;
}

int n, res;
int dp[100];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> wire[i].a >> wire[i].b;
	sort(wire, wire + n, cmp);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (wire[j].b < wire[i].b) {
				dp[i] = max(dp[i], dp[j] + 1);
				res = max(res, dp[i]);
			}
		}
	}

	cout << n - (res + 1);

	return 0;
}