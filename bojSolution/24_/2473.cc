#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll myabs(ll val) {
	if (val >= 0) return val;
	return val * -1;
}

int n;
tuple<ll, int, int, int> res{ 3000000000, -1, -1, -1 };
vector<ll> sol;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n; sol.resize(n);
	for (int i = 0; i < n; ++i) cin >> sol[i];
	sort(sol.begin(), sol.end());

	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int m, req;
			m = sol[i] + sol[j];
			req = lower_bound(sol.begin(), sol.end(), -m) - sol.begin();
			for (int k = req-1; k < req+2; ++k) {
				if (k == i || k == j || k < 0 || k >= n) continue;
				if (get<0>(res) > abs(m + sol[k])) {
					res = { abs(m + sol[k]), i, j, k };
				}
			}
		}
	}

	vector<ll> ans = { sol[get<1>(res)], sol[get<2>(res)], sol[get<3>(res)] };
	sort(ans.begin(), ans.end());
	for (int a : ans) cout << a << " ";

	return 0;
}