#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	long long int x, y, n;

	cin >> x >> y;
	n = y - x;

	if (n == 0) {
		cout << 0;
		return 0;
	}

	if (floor(sqrt(n)) == sqrt(n)) {
		cout << floor(sqrt(n)) * 2 - 1;
	}
	else {
		if (n < floor(sqrt(n)) + 1 + pow(floor(sqrt(n)), 2)) {
			cout << floor(sqrt(n)) * 2;
		}
		else {
			cout << floor(sqrt(n)) * 2 + 1;
		}
	}

	return 0;
}