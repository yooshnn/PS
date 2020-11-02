#include <bits/stdc++.h>
using namespace std;

string src, tar;
vector<int> fail, KMP;

void getFail(string t) {
	fail.resize(t.length());
	int j = 0;
	for (int i = 1; i < t.length(); ++i) {
		while (j > 0 && t[i] != t[j]) j = fail[j - 1];
		if (t[i] == t[j]) fail[i] = ++j;
	}
}

int getKMP(string s, string t) {
	int ret = 0, sLen = s.length(), tLen = t.length(), j = 0;

	for (int i = 0; i < sLen; ++i) {
		while (j > 0 && s[i] != t[j]) j = fail[j - 1];
		if (s[i] == t[j]) {
			if (j == tLen - 1) {
				ret++;
				j = fail[j];
			}
			else j++;
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m; string s, t = "";
	cin >> n >> m >> s;
	for (int i = 0; i < n; ++i) t += "IO";
	t += "I";
	getFail(t);
	cout << getKMP(s, t);

	return 0;
}