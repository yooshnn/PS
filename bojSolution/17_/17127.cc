#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, res = 0;
	int a[10];

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];

	for (int i = 1; i < n - 2; ++i) {
		for (int j = i + 1; j < n - 1; ++j) {
			for (int k = j + 1; k < n; ++k) {
				int q = 1, w = 1, e = 1, r = 1;
				for (int l = 0; l < i; ++l) q *= a[l];
				for (int l = i; l < j; ++l) w *= a[l];
				for (int l = j; l < k; ++l) e *= a[l];
				for (int l = k; l < n; ++l) r *= a[l];
				res = max(res, q + w + e + r);
			}
		}
	}

	cout << res;

	return 0;
}