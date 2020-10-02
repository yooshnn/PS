#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int res = 5000, c;
	while (cin >> c) {
		if (c == 1) res -= 500;
		if (c == 2) res -= 800;
		if (c == 3) res -= 1000;
	}
	cout << res;

	return 0;
}