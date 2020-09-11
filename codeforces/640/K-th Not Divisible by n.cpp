#include <bits/stdc++.h>
using namespace std; int TEST;

long long n, k;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin >> TEST;

	while (TEST--) {
		cin >> n >> k;
		cout << (k-1) * n / (n - 1) +1 << "\n";
	}

	return 0;
}