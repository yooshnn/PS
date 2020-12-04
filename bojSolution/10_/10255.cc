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
	vector<int> res;
	int TEST; cin >> TEST; while (TEST--) {

		ll x[2], y[2];
		ll rx[4], ry[4];

		cin >> rx[0] >> ry[0] >> rx[2] >> ry[2];
		cin >> x[0] >> y[0] >> x[1] >> y[1];
		rx[1] = rx[0], ry[1] = ry[2];
		rx[3] = rx[2], ry[3] = ry[0];

		bool inf = false;
		if (x[0] == x[1]) {
			if (x[0] == rx[0] || x[0] == rx[2]) {
				if (min(y[0], y[1]) < min(ry[0], ry[1])) {
					if (max(y[0], y[1]) > min(ry[0], ry[1])) inf = true;
				}
				if (min(ry[0], ry[1]) <= min(y[0], y[1]) && min(y[0], y[1]) < max(ry[0], ry[1])) inf = true;
				//cout << min(ry[0], ry[1]) << " < " << min(y[0], y[1]) << " < " << max(ry[0], ry[1]) << "\n";
			}
		}
		if (y[0] == y[1]) {
			if (y[0] == ry[0] || y[0] == ry[1]) {
				if (min(x[0], x[1]) < min(rx[2], rx[1])) {
					if (max(x[0], x[1]) > min(rx[2], rx[1])) inf = true;
				}
				if (min(rx[2], rx[1]) <= min(x[0], x[1]) && min(x[0], x[1]) < max(rx[2], rx[1])) inf = true;
				//if (min(rx[2], rx[1]) <= min(x[0], x[1]) && min(x[0], x[1]) <= max(rx[2], rx[1])) cout << min(rx[2], rx[1]) << " < " << min(x[0], x[1]) << " < " << max(rx[2], rx[1]) << "\n";
			}
		}
		if (inf) {
			res.push_back(4);
			cout << 4 << "\n";
			continue;
		}

		int req = 0;
		int e = 0;
		for (int i = 0; i < 4; ++i) {
			if (lineIntersect({ {x[0], y[0]}, {x[1], y[1]} }, { {rx[i], ry[i]}, {rx[(i + 1) % 4], ry[(i + 1) % 4]} })) req += 1;
			if (lineIntersect({ { x[0], y[0] }, { x[1], y[1] } }, { { rx[i], ry[i] }, { rx[i], ry[i] } })) {
				e += 1;
			}
		}
		cout << req - e << "\n";
		res.push_back(req - e);
		//cout << "cross: " << req << ", e: " << e << "\n";

	}
	// for (auto i : res) cout << i << " ";
}