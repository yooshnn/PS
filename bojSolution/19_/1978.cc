#include <iostream>
#include <cstring>

bool isprime[1001];
int N, num, res = 0;

using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	memset(isprime, true, sizeof(bool) * 1000);

	isprime[1] = false;

	for (int i = 2; i <= 1000; ++i) {
		if (!isprime[i]) continue;
		for (int j = 2 * i; j <= 1000; j += i) {
			isprime[j] = false;
		}
	}
	cin >> N;
	while (N-- > 0) {
		cin >> num;
		if (isprime[num]) res++;
	}

	cout << res;

	return 0;
}