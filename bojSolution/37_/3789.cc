#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> suffixArray;
ll res = 0;

int getLCP(vector<int>& sa, string& s) {
	int i, j, k, l = 0, m = 26, sLen = s.length();
	sa.resize(sLen, 0);

	// cnt: radix cnt | x: rank
	vector<int> cnt(max(sLen, m), 0), x(sLen, 0), y(sLen, 0);
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
	}

	int M = sLen + 1, ret = 2147483647;
	for (int c = 0; c < sLen; ++c) {
		if (sa[c] < sLen / 2) {
			ret = min(ret, sa[c]);
			c++;
			while (c < sLen && sa[c] < sLen / 2) {
				ret = min(ret, sa[c]);
				c++;
			}
			break;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int TEST; cin >> TEST; while (TEST--) {
		int g; cin >> g; string src; cin >> src;
		src += src;
		cout << getLCP(suffixArray, src) << "\n";
	}

	return 0;
}