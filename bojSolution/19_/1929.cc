#include <iostream>
#include <cstring>

bool isprime[1000001];
int M, N, sum_ = 0, min_ = 0;

using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	memset(isprime, true, sizeof(bool) * 1000000);

	isprime[1] = false;

	for (int i = 2; i <= 1000000; ++i) {
		if (!isprime[i]) continue;
		for (int j = 2 * i; j <= 1000000; j += i) {
			isprime[j] = false;
		}
	}
	cin >> M >> N;

	for (int i = M; i <= N; ++i) {
		if (isprime[i]) cout << i << "\n";
	}

	return 0;
}