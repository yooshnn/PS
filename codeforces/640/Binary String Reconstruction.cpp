#include <bits/stdc++.h>
using namespace std; int TEST;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin >> TEST;

	while (TEST--) {

		string res = "";
		int n0, n1, n2;
		cin >> n0 >> n1 >> n2;

		if (n1 == 0) {
			if (n0 == 0) {
				while (n2-- >= 0) res += "1";
				cout << res << "\n";
				continue;
			}
			else {
				while (n0-- >= 0) res += "0";
				cout << res << "\n";
				continue;
			}
		}

		n1 -= 1;
		while (n0-- >= 0) res += "0";
		while (n2-- >= 0) res += "1";

		int cur = n1 % 2;
		while (n1-- > 0) {
			if (n1 % 2 == cur) res += "1";
			else res += "0";
		}
		
		cout << res << "\n";

	}

	return 0;
}