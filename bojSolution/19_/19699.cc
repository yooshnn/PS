#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> h(9);
set<int> r;

void dfs(int depth, int id, int s) {
	if (depth == m) {
		if (s == 1) return;
		for (int i = 2; i < s; ++i) {
			if (s % i == 0) return;
		}
		r.insert(s);
		return;
	}
	for (int i = id + 1; i < n; ++i) dfs(depth + 1, i, s + h[i]);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> h[i];

	for (int i = 0; i < n; ++i) dfs(1, i, h[i]);

	if (r.size() == 0) cout << -1;
	for (int i : r) cout << i << " ";

	return 0;
}