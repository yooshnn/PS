#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, res = 0; cin >> n;

	for (int i = 1; i <= n; ++i) {
		int a = 0;
		string s = to_string(i);
		for (char c : s) a += int(c - '0');
		if (i % a == 0) res++;
	}
	cout << res;

	return 0;
}