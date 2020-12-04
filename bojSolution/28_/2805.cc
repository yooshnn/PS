#include <bits/stdc++.h>
#define y1 Y1
using namespace std;
typedef long long ll;

ll tree[1000000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> tree[i];
	sort(tree, tree + n);

	ll lp = 0, rp = tree[n-1], res = 0;
	while (lp+1 < rp) {
		ll mid = (lp + rp) / 2;
		ll b = lower_bound(tree, tree + n, mid) - tree;
		ll t = 0;
		for (int i = b; i < n; ++i) t += tree[i] - mid;
		if (t >= m) {
			res = max(res, mid);
			lp = mid;
		}
		else {
			rp = mid;
		}
	}
	cout << res;

}