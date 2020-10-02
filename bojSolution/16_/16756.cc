#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	long long c, p, r = 3000000000;
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> c;
		if (i == 0) {
			p = c;
			continue;
		}
		if (abs(c - p) < r) r = abs(c - p);
		p = c;
	}

	cout << r;

	return 0;
}