#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, carlos;
	cin >> n >> carlos;
	for (int i = 1; i < n; ++i) {
		int t; cin >> t;
		if (t > carlos) carlos = -1;
	}
	cout << (carlos >= 0 ? "S" : "N");

	return 0;
}