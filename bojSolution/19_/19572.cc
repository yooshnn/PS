#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

double p, q, r;
double a, b, c;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> p >> q >> r;
	a = (p + q - r) / 2;
	b = (r + p - q) / 2;
	c = (q - p + r) / 2;

	if (a > 0 && b > 0 && c > 0) {
		cout << 1 << "\n";
		cout << fixed << setprecision(1) << round(a * 10) / 10 << " " << round(b * 10) / 10 << " " << round(c * 10) / 10;
	}
	else {
		cout << -1;
	}

	return 0;
}