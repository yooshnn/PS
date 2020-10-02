#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPalindrome(string s) {
	for (int i = 0; i < s.length() / 2; ++i) {
		if (s[i] != s[s.length() - 1 - i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int TEST; cin >> TEST; while (TEST--) {
		int found = 0, K; cin >> K;
		vector<string> s(K);
		for (int i = 0; i < K; ++i) cin >> s[i];
		for (int i = 0; i < K; ++i) {
			if (found) break;
			for (int j = 0; j < K; ++j) {
				if (found) break;
				if (i == j) continue;
				if (isPalindrome(s[i] + s[j])) {
					found = 1;
					cout << s[i] << s[j] << "\n";
				}
			}
		}
		if (!found) cout << 0 << "\n";
	}

	return 0;
}