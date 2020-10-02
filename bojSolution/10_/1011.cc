#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int T, x, y, n;
	cin >> T;

	while(--T >= 0) {
		cin >> x >> y;
		n = y - x;

		if (floor(sqrt(n)) == sqrt(n)) {
			cout << floor(sqrt(n)) * 2 - 1;
		}
		else {
			if (n < floor(sqrt(n))+1 + pow(floor(sqrt(n)),2)) {
				cout << floor(sqrt(n)) * 2;
			}
			else {
				cout << floor(sqrt(n)) * 2 + 1;
			}
		}
		cout << "\n";
	}

	return 0;
}