#include <iostream>
#include <iomanip>
using namespace std;

int T, n, r;
int dp[31];
double f[31];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);

	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i < 31; ++i) {
		f[i] = f[i - 1] * i;
	}

	cin >> T;
	while (T--) {
		cin >> r >> n;
		cout << fixed << setprecision(0) << (f[n] / f[r]) / f[n-r] << "\n";
	}

	return 0;
}