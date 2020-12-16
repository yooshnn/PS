#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, t = 0; cin >> n; vector<ll> v(n);
	for (ll& i : v) cin >> i, t += i; sort(v.begin(), v.end());

	if (n == 1) {
		cout << t; return 0;
	}

	t -= v[n - 1] * 2;
	if (t < 0) cout << -t;
	else cout << (t&1);

}