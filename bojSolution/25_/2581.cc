#include <iostream>
#include <cstring>

bool isprime[10001];
int M, N, sum_ = 0, min_ = 0;

using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	memset(isprime, true, sizeof(bool) * 10000);

	isprime[1] = false;

	for (int i = 2; i <= 10000; ++i) {
		if (!isprime[i]) continue;
		for (int j = 2 * i; j <= 10000; j += i) {
			isprime[j] = false;
		}
	}
	cin >> M >> N;

	for (int i = M; i <= N; ++i) {
		if (isprime[i]) {
			if (min_ == 0) min_ = i;
			sum_ += i;
		}
	}

	if (min_ == 0) {
		cout << -1;
	}
	else {
		cout << sum_ << "\n" << min_;
	}

	return 0;
}