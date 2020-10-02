#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll myPow(ll a, ll b, ll c) {
	if (b == 0) return 1;
	ll ret, req = myPow(a, b / 2, c) % c;

	ret = (req * req) % c;
	if (b % 2 == 1) ret = (ret * a) % c;
	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll a, b, c; cin >> a >> b >> c;
	cout << myPow(a, b, c);

	return 0;
}