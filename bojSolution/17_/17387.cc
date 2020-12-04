#include <bits/stdc++.h>
#define y1 Y1
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int ccw(pll a, pll b, pll c) {
	ll res = (a.first * b.second + b.first * c.second + c.first * a.second)
		- (a.second * b.first + b.second * c.first + c.second * a.first);
	return (res == 0 ? 0 : res / (res > 0 ? res : -res));
}
int lineIntersect(pair<pll, pll> x, pair<pll, pll> y) {
	pll a = x.first, b = x.second, c = y.first, d = y.second;
	ll ab = ccw(a, b, c) * ccw(a, b, d), cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	cout << (lineIntersect({ {x1, y1}, {x2, y2} }, { {x3, y3}, {x4, y4} }) ? 1 : 0);
}