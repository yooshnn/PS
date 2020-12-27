#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll xorSum(ll n) {
	int m = n % 4;
	if (m == 0) return n;
	if (m == 1) return 1;
	if (m == 2) return n + 1;
	return 0;
}
ll xorSum(ll l, ll r) {
	return xorSum(l - 1) ^ xorSum(r);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	ll n, t0, t, r = 0; cin >> n;
	while (n--) {
		cin >> t0 >> t;
		r ^= xorSum(t0, t0 + t - 1);
	}
	cout << (r == 0 ? "cubelover" : "koosaga");
}