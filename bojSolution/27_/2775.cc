#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int home[15][15];

	for (int i = 1; i < 15; ++i) {
		home[0][i] = i;
	}
	for (int i = 1; i < 15; ++i) {
		for (int j = 1; j < 15; ++j) {
			int temp = 0;
			for (int k = 1; k <= j; ++k) {
				temp += home[i - 1][k];
			}
			home[i][j] = temp;
		}
	}
	int T, k, n;
	cin >> T;
	while (T-- > 0) {
		cin >> k >> n;
		cout << home[k][n] << "\n";
	}

	return 0;
}