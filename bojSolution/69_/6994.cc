#include <bits/stdc++.h>
#define y1 Y1
using namespace std;
typedef long long ll;
//typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int ccw(pdd a, pdd b, pdd c) {
	ll res = (a.first * b.second + b.first * c.second + c.first * a.second)
		- (a.second * b.first + b.second * c.first + c.second * a.first);
	return (res == 0 ? 0 : res / (res > 0 ? res : -res));
}
int lineIntersect(pair<pdd, pdd> x, pair<pdd, pdd> y) {
	pdd a = x.first, b = x.second, c = y.first, d = y.second;
	ll ab = ccw(a, b, c) * ccw(a, b, d), cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	vector<int> res;
	int TEST; cin >> TEST; while (TEST--) {
		double x[4], y[4];
		double r, xc[2], yc[2];
		cin >> r >> xc[0] >> yc[0] >> x[0] >> y[0] >> x[2] >> y[2];
		x[1] = x[0], y[1] = y[2], x[3] = x[2], y[3] = x[0];

		bool res = false;
		pair<pdd, pdd> circle, rect;
		for (int rr = 0; rr < 4 && !res; ++rr) {
			rect = { { x[rr], y[rr] }, {x[(rr + 1) % 4], y[(rr + 1) % 4]} };
			if (r == 1) break;
			for (int i = 0, prec = 720; i < prec && !res; ++i) {
				xc[1] = xc[0] + r * cos(2 * acos(-1) * i / prec);
				yc[1] = yc[0] + r * sin(2 * acos(-1) * i / prec);
				circle = { {xc[0], yc[0]}, {xc[1], yc[1]} };
				//cout << xc[1] << ", " << yc[1] << "\n";
				if (lineIntersect(circle, rect)) res = true;
			}
		}
		if (res) {
			cout << "The given circle and rectangle overlap.";
		}
		else {
			cout << "The given circle and rectangle do not overlap.";
		}
		cout << "\n";
	}
}