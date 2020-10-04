#include <bits/stdc++.h>
using namespace std;

vector<int> manacher(string& src) {
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
	return ret;
}

int main() {
	string src; cin >> src;
	vector<int> pal = manacher(src);

	for (int i : pal) cout << i << " ";
}