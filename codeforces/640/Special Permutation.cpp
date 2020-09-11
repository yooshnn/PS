#include <bits/stdc++.h>
using namespace std; int TEST;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin >> TEST;

	while (TEST--) {

		int n; cin >> n;

		if (n < 4) {
			cout << -1 << "\n";
			continue;
		}

		int c = n;
		if (c % 2 == 0) c--;
		while (c >= 1) {
			cout << c << " ";
			c -= 2;
		}
		cout << "4 2 ";
		c = 6;
		while (c <= n) {
			cout << c << " ";
			c += 2;
		}
		cout << "\n";

	}

	return 0;
}