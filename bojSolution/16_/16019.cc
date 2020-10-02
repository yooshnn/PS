#include <bits/stdc++.h>
using namespace std;

int d[5];
int res[5][5];

int main() {
	for (int i = 1; i <= 4; ++i) {
		int input; cin >> input;
		res[0][i] = res[0][i - 1] + input;
		res[i][0] = res[0][i];
	}
	for (int i = 1; i <= 3; ++i) {
		for (int j = i + 1; j <= 4; ++j) {
			res[i][j] = res[0][j] - res[0][i];
			res[j][i] = res[i][j];
		}
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}