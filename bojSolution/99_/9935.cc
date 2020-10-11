#include <bits/stdc++.h>
using namespace std;

string src, tar;
vector<char> res;
vector<int> fail, KMP, dp;

void getFail(string t) {
	fail.resize(t.length());
	int j = 0;
	for (int i = 1; i < t.length(); ++i) {
		while (j > 0 && t[i] != t[j]) j = fail[j - 1];
		if (t[i] == t[j]) fail[i] = ++j;
	}
}
bool getKMP(string s, string t) {
	int sLen = s.length(), tLen = t.length(), j = 0, ptr = 0;
	dp.resize(s.length(), 0); res.resize(s.length());

	for (int i = 0; i < sLen; ++i) {
		while (j > 0 && s[i] != t[j]) j = fail[j - 1];
		if (s[i] == t[j]) j++;
		res[ptr] = s[i];
		dp[ptr] = j;
		if (j == tLen) {
			ptr -= tLen;
			if (i == sLen - 1 && ptr < 0) return false;
			if (ptr < 0) ptr = sLen + ptr;
			j = dp[ptr];
		}
		ptr++;
		if (i < sLen - 1 && ptr >= sLen) ptr -= sLen;
	}
	res.resize(ptr);
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> src >> tar;
	getFail(tar);
	if (getKMP(src, tar)) for (char i : res) cout << i;
	else cout << "FRULA";

	return 0;
}