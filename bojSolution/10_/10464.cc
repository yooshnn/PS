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

	int TEST; cin >> TEST; while (TEST--) {
		ll a, b; cin >> a >> b;
		cout << xorSum(a, b) << "\n";
	}

	// cout << endl; system("pause");
}