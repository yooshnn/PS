#include <iostream>
using namespace std;

int T, x, y, n;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);

	cin >> T;
	while (T--) {
		cin >> x >> y >> n;
		int k;
		if ((n / x) * x + y <= n) cout << (n / x) * x + y << "\n";
		else cout << (n / x - 1) * x + y << "\n";
	}

	return 0;
}
