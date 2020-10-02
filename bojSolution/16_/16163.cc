#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll manacher(string s) {
	ll ret = 0;
	vector<ll> pal(s.length());
	ll c = 0, r = 0;

	for (ll i = 0; i < s.length(); ++i) {
		ll sym = 2 * c - i;
		if (i < r) pal[i] = min(r - i, pal[sym]);
		while (i - pal[i] > 0 && i + pal[i] - 1 < s.length() && s[i - pal[i] - 1] == s[i + pal[i] + 1]) pal[i] ++;
		if (pal[i] + i > r) {
			r = pal[i] + i; c = i;
		}
	}
	for (ll p : pal) {
		ret += (p + 1) / 2;
	}

	return ret;
}

int main() {
	string s, t = "#"; cin >> s;

	for (ll i = 0; i < s.length(); ++i) {
		t += s[i];
		t += "#";
	}

	cout << manacher(t);

	return 0;
}