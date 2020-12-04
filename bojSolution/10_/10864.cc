#include <bits/stdc++.h>
using namespace std;

int res[1001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	while (m--) {
		int p, q; cin >> p >> q;
		res[p]++;
		res[q]++;
	}
	for (int i = 1; i <= n; ++i) cout << res[i] << "\n";
}