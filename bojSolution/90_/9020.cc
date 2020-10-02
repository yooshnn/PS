#include <iostream>
#include <cstring>

bool isprime[246913];
int T, n;

using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	memset(isprime, true, sizeof(bool) * 246913);

	isprime[1] = false;

	for (int i = 2; i <= 246913; ++i) {
		if (!isprime[i]) continue;
		for (int j = 2 * i; j <= 246913; j += i) {
			isprime[j] = false;
		}
	}

	cin >> T;

	while (T-- > 0) {
		cin >> n;
		int a = -1000, b = 11000;
		for (int i = 2; i < n/2 + 1; ++i) {
			if (isprime[i] && isprime[n-i]) {
				if (n - 2 * i < b - a) {
					a = i;
					b = n - i;
				}
			}
		}
		cout << a << " " << b << "\n";
	}

	return 0;
}