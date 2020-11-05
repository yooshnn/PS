#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int TEST; cin >> TEST; while (TEST--) {
		int r, g, b;
		double rSum, gSum, bSum;
		rSum = gSum = bSum = 0;
		for (int i = 0; i < 10; ++i) {
			cin >> r >> g >> b;
			rSum += r; gSum += g; bSum += b;
		}
		cout << round(rSum / 10) << " " << round(gSum / 10) << " " << round(bSum / 10) << "\n";
	}
}