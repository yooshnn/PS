#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	ll n; cin >> n;
	ll res = 1;

	ll lp = (n + 1) / 2, rp = n - 1, c = 2;
	while (lp <= rp) {
		res += (rp - lp + 1) * c;
		c += 1;
		rp = lp - 1;
		lp = (n - 1) / c + 1;
	}

	for (ll i = 1; i < lp; ++i) {
		res += (n - 1) / i + 1;
	}

	cout << res;
}