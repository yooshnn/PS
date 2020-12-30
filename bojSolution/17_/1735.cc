#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int a, b, c, d; cin >> a >> b >> c >> d;
	int m = __gcd(b, d);
	a *= d/m, b *= d/m;
	c *= b/d, d = b;
	a += c;
	m = __gcd(a, b);
	cout << a/m << " " << b/m;

}