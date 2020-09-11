#include <iostream>
using namespace std;

int T, N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);

	cin >> T;
	while (T--) {
		cin >> N;
		int tr = 0;
		if (N == 0) {
			cout << "0\n";
			continue;
		}

		unsigned long long n = N;
		while (n != 1) {
			if (n % 6 == 0) {
				tr += 1;
				n /= 6;
			}
			else if (n % 3 == 0) {
				tr += 2;
				n /= 3;
			}
			else {
				tr = -1;
				break;
			}
		}
		cout << tr << "\n";
	}

	return 0;
}