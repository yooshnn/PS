#include <bits/stdc++.h>
using namespace std;

void manacher(string& src) {
	int srcLen = src.size(); src.resize(srcLen * 2 + 1, '#');
	for (int i = srcLen - 1; i >= 0; --i) src[i * 2 + 1] = src[i], src[i] = '#';

	int c = 0, r = 0, len = src.size();
	vector<int> ret(len, 0);
	for (int i = 0; i < len; ++i) {
		int sym = 2 * c - i;
		if (i < r) ret[i] = min(r - i, ret[sym]);
		while (i - ret[i] > 0 && i + ret[i] - 1 < len && src[i - ret[i] - 1] == src[i + ret[i] + 1]) ret[i]++;
		if (ret[i] + i > r) r = ret[i] + i, c = i;
	}
	int req = *max_element(ret.begin(), ret.end());
	if (req == 1) return;
	for (int i = ret.size() - 1; i >= 1; --i) {
		if (ret[i] == req) {
			for (int j = 0; j < req; ++j) {
				cout << src[i - ret[i] + 1 + j * 2];
			} cout << "\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int TEST; cin >> TEST; for (int test = 1; test <= TEST; ++test) {
		string src; cin >> src;
		cout << "Case #" << test << ":\n";
		manacher(src);
	}
}