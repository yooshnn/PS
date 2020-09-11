#include <bits/stdc++.h>
using namespace std;
int TESTS;

int n;
bool zApp = false, oApp = false;
int zPos = -1, oPos = -1;
string s;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin >> TESTS;

	while (TESTS--) {
		zApp = false;
		oApp = false;

		cin >> n >> s;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') {
				zApp = true;
				zPos = i;
			}
			if (!oApp) {
				if (s[i] == '1') {
					oApp = true;
					oPos = i;
				}
			}
		}

		if ((!zApp || !oApp) || (zPos < oPos)) cout << s;
		else {
			for (int i = 0; i < n; ++i) {
				if (i < oPos || i >= zPos) cout << s[i];
			}
		}

		cout << "\n";
	}

	return 0;
}
