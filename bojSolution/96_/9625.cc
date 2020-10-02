#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int K;
	int a[46], b[46];

	a[0] = 1; b[0] = 0;
	a[1] = 0; b[1] = 1;

	cin >> K;
	for (int i = 1; i <= K; ++i) {
		a[i] = b[i - 1];
		b[i] = b[i - 1] + a[i - 1];
	}

	cout << a[K] << " " << b[K];


	return 0;
}