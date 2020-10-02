#include <bits/stdc++.h>
using namespace std;

int bug[21];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	bug[1] = 1;

	int n, res = 0; cin >> n;
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			bug[i] += bug[j];
			if (i - j == 3 && j % 2 == 1) bug[i - 3] = 0;
			if (i - j == 4 && j % 2 == 0) bug[i - 4] = 0;
		}
	}

	for (int i = 1; i <= n; ++i) {
		res += bug[i];
	}

	cout << res;

	return 0;
}