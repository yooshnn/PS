#include <iostream>
#define P 1000000007
using namespace std;
typedef unsigned long long ull;

int M, N, K;
ull num, denom;
ull f[4000001];

ull mypow(ull base, ull exp) {
	if (exp == 0) return 1;
	if (exp == 1) return base;
	if (exp % 2 == 1) return base * mypow(base, exp - 1) % P;
	ull temp = mypow(base, exp / 2);
	return (temp * temp) % P;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);

	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i <= 4000000; ++i) {
		f[i] = f[i - 1] * i;
		f[i] %= P;
	}

	cin >> M;
	for (int i = 0; i < M; ++i) {

		cin >> N >> K;

		num = f[N];
		denom = f[K] * f[N - K] % P;

		cout << (num)*mypow(denom, P - 2) % P << "\n";
	}

	return 0;
}