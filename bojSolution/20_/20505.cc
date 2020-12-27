#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353;

ll fastpow(ll a, ll b, ll c) {
	ll ret = 1;

	while (b > 0) {
		if (b & 1) ret = (ret * a) % c, b -= 1;
		else a = (a * a) % c, b >>= 1;
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s; cin >> s;
	ll res = 0, n = s.size();
	for (int i = 0; i < n; ++i) {
		res += ((((s[i] - '0') * fastpow(11, n - i - 1, MOD)) % MOD) * fastpow(2, i, MOD)) % MOD;
		res %= MOD;
	}

	cout << res;
}