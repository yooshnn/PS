#include <bits/stdc++.h>
using namespace std;

string src, tar;
vector<int> fail;

void getFail(string t) {
	fail.resize(0);
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

	int TEST; cin >> TEST; while (TEST--) {
		string src; cin >> src;

		string tar;

		tar = "TTT"; getFail(tar); cout << getKMP(src, tar) << " ";
		tar = "TTH"; getFail(tar); cout << getKMP(src, tar) << " ";
		tar = "THT"; getFail(tar); cout << getKMP(src, tar) << " ";
		tar = "THH"; getFail(tar); cout << getKMP(src, tar) << " ";
		tar = "HTT"; getFail(tar); cout << getKMP(src, tar) << " ";
		tar = "HTH"; getFail(tar); cout << getKMP(src, tar) << " ";
		tar = "HHT"; getFail(tar); cout << getKMP(src, tar) << " ";
		tar = "HHH"; getFail(tar); cout << getKMP(src, tar) << "\n";
	}

	return 0;
}