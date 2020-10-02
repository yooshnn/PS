#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> suffixArray, LCPArray;

void getLCP(vector<int>& sa, vector<int>& lcpa, string& s) {
	int i, j, k, l = 0, m = 26, sLen = s.length();
	sa.resize(sLen, 0);/* lcpa.resize(sLen, 0);*/

	// cnt: radix sort counts | x: rank
	vector<int> cnt(max(sLen, m), 0), x(sLen, 0), y(sLen, 0);
	// set d=1 rank -> calc prefix sum -> fill sa
	for (i = 0; i < sLen; ++i) cnt[x[i] = s[i] - 'a']++;
	for (i = 0; i < m; ++i) cnt[i] += (i == 0 ? 0 : cnt[i - 1]);
	for (i = sLen - 1; i >= 0; --i) sa[--cnt[x[i]]] = i;
	for (int len = 1, p = 1; p < sLen; len <<= 1, m = p + 1) {
		for (i = sLen - len - 1, p = 0; ++i < sLen;) y[p++] = i;
		for (i = 0; i < sLen; ++i) if (sa[i] >= len) y[p++] = sa[i] - len;
		for (i = 0; i < m; ++i) cnt[i] = 0;
		for (i = 0; i < sLen; ++i) cnt[x[y[i]]]++;
		for (i = 0; i < m; ++i) cnt[i] += (i == 0 ? 0 : cnt[i - 1]);
		for (i = sLen - 1; i >= 0; --i) sa[--cnt[x[y[i]]]] = y[i];
		swap(x, y); p = 1; x[sa[0]] = 1;
		for (i = 0; i < sLen - 1; ++i) x[sa[i + 1]] = sa[i] + len < sLen&& sa[i + 1] + len < sLen&& y[sa[i]] == y[sa[i + 1]] && y[sa[i] + len] == y[sa[i + 1] + len] ? p : ++p;
		/*cout << "x : "; for (int z : x) cout << z << " "; cout << "\n";
		cout << "y : "; for (int z : y) cout << z << " "; cout << "\n";*/
	}

	/*vector<int> rank(sLen, 0);
	for (i = 0; i < sLen; i++) rank[sa[i]] = i;
	for (i = 0; i < sLen; ++i) if (k = rank[i]) {
		j = sa[k - 1];
		while (i + l < sLen && j + l < sLen && s[i + l] == s[j + l]) l++;
		lcpa[k] = l;
		l = l ? l - 1 : 0;
	}*/
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s; cin >> s;
	getLCP(suffixArray, LCPArray, s);

	/*for (int i : suffixArray) cout << i << " ";
	cout << "\n";*/

	for (int i : suffixArray) {
		for (int j = i; j < s.length(); ++j) cout << s[j];
		cout << "\n";
	}

	return 0;
}