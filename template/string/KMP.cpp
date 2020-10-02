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

void getKMP(string s, string t) {
	int sLen = s.length(), tLen = t.length(), j = 0;

	for (int i = 0; i < sLen; ++i) {
		while (j > 0 && s[i] != t[j]) j = fail[j - 1];
		if (s[i] == t[j]) {
			if (j == tLen - 1) {
				KMP.push_back(i - tLen + 1 + 1);
				j = fail[j];
			}
			else j++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	getline(cin, src); getline(cin, tar);
	getFail(tar);
	getKMP(src, tar);

	cout << KMP.size() << "\n";
	for (int i : KMP) {
		cout << i << " ";
	}

	return 0;
}