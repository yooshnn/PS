#include <bits/stdc++.h>
using namespace std;

int manacher(string s) {
	int ret = 0;
	vector<int> pal(s.length());
	int c = 0, r = 0;

	for (int i = 0; i < s.length(); ++i) {
		int sym = 2 * c - i;
		if (i < r) pal[i] = min(r - i, pal[sym]);
		while (i - pal[i] > 0 && i + pal[i] - 1 < s.length() && s[i - pal[i] - 1] == s[i + pal[i] + 1]) pal[i] ++;
		if (pal[i] + i > r) {
			r = pal[i] + i; c = i;
		}
	}
	for (int p : pal) {
		ret = max(ret, p);
	}

	return ret;
}

int main() {
	string s, t = "#"; cin >> s;

	for (int i = 0; i < s.length(); ++i) {
		t += s[i];
		t += "#";
	}

	cout << manacher(t);

	return 0;
}