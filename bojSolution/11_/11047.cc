#include <iostream>
using namespace std;

int N, K;
int A[1000001];
int res = 0;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	cin >> N >> K;

	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = N - 1; i >= 0; --i) {
		if (K / A[i] > 0) {
			res += (K / A[i]);
			K -= A[i] * (K / A[i]);
		}
		if (K == 0) {
			break;
		}
	}

	cout << res;

	return 0;
}