#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	long long n, c = 1;
	cin >> n;
	while (c++) {
		if (n == 1) break;

		if (n % 2 == 0) n = n / 2;
		else n = 3 * n + 1;
	}
	cout << c - 1;

	return 0;
}