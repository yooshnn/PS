#include <bits/stdc++.h>
using namespace std;

bool isPal(string s) {
	for (int i = 0; i < s.length() / 2; ++i) {
		if (s[i] != s[s.length() - 1 - i]) return false;
	}
	return true;
}

int main() {
	string s; cin >> s;

	if (!isPal(s)) {
		cout << s.length();
	}
	else {
		s = s.substr(0, s.length() - 1);
		if (!isPal(s)) {
			cout << s.length();
		}
		else {
			cout << -1;
		}
	}

	return 0;
}