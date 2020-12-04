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

	int TEST; cin >> TEST; while (TEST--) {

		ll x[2], y[2];
		ll rx[4], ry[4];

		cin >> x[0] >> y[0] >> x[1] >> y[1];
		cin >> rx[0] >> ry[0] >> rx[1] >> ry[1];
		rx[2] = min(rx[0], rx[1]), rx[3] = max(rx[0], rx[1]);
		ry[2] = (rx[2] == rx[0] ? ry[1] : ry[0]), ry[3] = (rx[3] == rx[0] ? ry[1] : ry[0]);

		sort(rx, rx + 4);
		sort(ry, ry + 4);
		swap(ry[1], ry[3]);

		if (min({ rx[0], rx[1], rx[2], rx[3] }) <= min({ x[0], x[1] }) &&
			max({ rx[0], rx[1], rx[2], rx[3] }) >= max({ x[0], x[1] }) &&
			min({ ry[0], ry[1], ry[2], ry[3] }) <= min({ y[0], y[1] }) &&
			max({ ry[0], ry[1], ry[2], ry[3] }) >= max({ y[0], y[1] })) {
			cout << "T" << "\n";
			continue;
		}

		bool req = false;
		for (int i = 0; i < 4; ++i) {
			if (lineIntersect({ {x[0], y[0]}, {x[1], y[1]} }, { {rx[i], ry[i]}, {rx[(i + 1) % 4], ry[(i + 1) % 4]} })) req = true;
		}
		cout << (req ? "T" : "F") << "\n";

	}
}