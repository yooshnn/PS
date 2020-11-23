#include <bits/stdc++.h>
using namespace std;

bool DEBUG = 0;

int n; string s;
vector<int> root;

int manacher(string& oldSrc) {
	int srcLen = oldSrc.size(); string src(srcLen * 2 + 1, '#');
	root.resize(srcLen + 1);

	for (int i = 0; i < srcLen; ++i) {
		if (i < n / 2 + (n % 2)) src[i * 4 + 1] = oldSrc[i];
		else src[srcLen * 2 - (i - n / 2) * 4 + 1 - 2 * (n % 2 == 0)] = oldSrc[i];
	}

	int c = 0, r = 0, len = src.size();
	vector<int> ret(len, 0);
	for (int i = 0; i < len; ++i) {
		int sym = 2 * c - i;
		if (i < r) ret[i] = min(r - i, ret[sym]);
		while (i - ret[i] > 0 && i + ret[i] - 1 < len && src[i - ret[i] - 1] == src[i + ret[i] + 1]) ret[i]++;
		if (ret[i] + i > r) r = ret[i] + i, c = i;
		// cout << i - ret[i] / 2 << "\n";
		if (src[i] == '#') root[i / 2 - ret[i] / 2] = max(root[i / 2 - ret[i] / 2], ret[i]);
	}
	for (int i = 1; i < srcLen; ++i) root[i] = max(root[i], root[i - 1] - 2);

	int res = 0;
	for (int i = 1; i < n; i += 2) {
		if (ret[i + 1] / 2 * 2 == i + 1) res = max(res, i + root[i + 1] + 1);
	}

	return res / 2;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	if (!DEBUG) cin >> n >> s;
	else cin >> s; n = s.size();
	cout << manacher(s);
	if (DEBUG) { for (int i = 0; i < n; ++i) cout << root[i] << " "; cout << "\n"; }

	return 0;
}