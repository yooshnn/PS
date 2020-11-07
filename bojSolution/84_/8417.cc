#include <bits/stdc++.h>
using namespace std;

bool manacher(string& src) {
	int c = 0, r = 0, len = src.size();
	vector<int> ret(len, 0);
	for (int i = 0; i < len; ++i) {
		int sym = 2 * c - i;
		if (i < r) ret[i] = min(r - i, ret[sym]);
		while (i - ret[i] > 0 && i + ret[i] - 1 < len && src[i - ret[i] - 1] == src[i + ret[i] + 1]) ret[i]++;
		if (ret[i] + i > r) r = ret[i] + i, c = i;
		if (ret[i] >= 2) return true;
	}
	return false;
}

int main() {
	int r1 = 0, r2 = 0;
	int TEST; cin >> TEST; while (TEST--) {
		string src; cin >> src;
		int srcLen = src.size(); src.resize(srcLen * 2 + 1, '#');
		for (int i = srcLen - 1; i >= 0; --i) src[i * 2 + 1] = src[i], src[i] = '#';

		r1 += manacher(src);
		for (char& c : src) {
			if (c == 'j') c = 'i';
			else if (c == 'd') c = 'b';
			else if (c == 'p') c = 'b';
		}
		r2 += manacher(src);
	}
	cout << r1 << "\n" << r2;
}