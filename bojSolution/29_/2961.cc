#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n;
vector<pii> v;
int res = 1e10;

void solve(int d, int id, int l, pii val) {
	if (d == l) {
		res = min(res, abs(val.first - val.second));
		return;
	}
	for (int i = id + 1; i < n; ++i) {
		solve(d + 1, i, l, { val.first * v[i].first, val.second + v[i].second });
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n; v.resize(n);
	for (pii& x : v) cin >> x.first >> x.second;

	for (int i = 1; i <= n; ++i) {
		for (int c = 0; c < n - i + 1; ++c) {
			solve(1, c, i, { v[c] });
		}
	}

	cout << res;

}