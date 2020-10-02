#include <iostream>
using namespace std;

int n, r = 0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		if (n % i == 0) r += i;
	}
	cout << 5 * r - 24;
	return 0;
}