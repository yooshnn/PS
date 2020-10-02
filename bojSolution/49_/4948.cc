#include <iostream>
#include <cstring>

bool isprime[246913];
int M, res;

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

	while (1) {
		cin >> M;
		if (M == 0) break;
		res = 0;
		for (int i = M+1; i <= M * 2; ++i) {
			if (isprime[i]) res++;
		}
		cout << res << "\n";
	}

	return 0;
}