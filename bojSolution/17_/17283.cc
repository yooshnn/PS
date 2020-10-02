#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	double l, r;
	long long b = 1, res = 0;
	cin >> l >> r;

	while (1) {
		l = floor(l * r / 100);
		if (l <= 5) break;
		b *= 2;
		res += b * l;
	}
	cout << res;

	return 0;
}