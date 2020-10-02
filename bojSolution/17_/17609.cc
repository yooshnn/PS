#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
	//cout << "CHECKING " << s << "\n";
	for (int i = 0; i < s.length() / 2; ++i) if (s[i] != s[s.length() - 1 - i]) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int TEST; cin >> TEST; while (TEST--) {
		string s; cin >> s;
		int lp = -1, rp = s.length(), res = 0;
		while (1) {
			lp++; rp--;
			if (lp >= rp) break;

			if (s[lp] == s[rp]) continue;

			if (isPalindrome(s.substr(lp + 1, rp - lp))) {
				res = 1; break;
			}
			else if (isPalindrome(s.substr(lp, rp - lp))) {
				res = 1; break;
			}
			else {
				res = 2; break;
			}
		}
		cout << res << "\n";
	}


	return 0;
}
