#include <iostream>
#include <cmath>
using namespace std;

double dist(int, int, int, int);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t, x1, y1, r1, x2, y2, r2;
	cin >> t;
	while (t-- > 0) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << -1 << "\n";
		}
		else if ((dist(x1, y1, x2, y2) > r1 + r2) || (dist(x1, y1, x2, y2) + r2 < r1) || (dist(x1, y1, x2, y2) + r1 < r2)) {
			cout << 0 << "\n";
		}
		else if ((abs(dist(x1, y1, x2, y2) - r1 - r2) < 0.0001) || (abs(dist(x1, y1, x2, y2) - r1 + r2) < 0.0001) || (abs(dist(x1, y1, x2, y2) + r1 - r2) < 0.0001)) {
			cout << 1 << "\n";
		}
		else {
			cout << 2 << "\n";
		}
	}

	return 0;
}

double dist(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}