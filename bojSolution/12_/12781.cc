#include <bits/stdc++.h>
#define y1 Y1
using namespace std;
typedef pair<int, int> pii;

int ccw(pii a, pii b, pii c) {
	int res = (a.first * b.second + b.first * c.second + c.first * a.second)
		- (a.second * b.first + b.second * c.first + c.second * a.first);
	return res / (res > 0 ? res : -res);
}
int lineIntersect(pair<pii, pii> x, pair<pii, pii> y) {
	pii a = x.first, b = x.second, c = y.first, d = y.second;
	int ab = ccw(a, b, c) * ccw(a, b, d), cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	cout << (lineIntersect({ {x1, y1}, {x2, y2} }, { {x3, y3}, {x4, y4} }) ? 1 : 0);
}