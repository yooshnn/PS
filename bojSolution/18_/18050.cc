#include <bits/stdc++.h>
using namespace std;

bool manacher(vector<int>& seq, string& src) {
	int srcLen = src.size();

	int c = 0, r = 0, len = src.size();
	vector<int> ret(len, 0);
	for (int i = 0; i < len; ++i) {
		int sym = 2 * c - i;
		if (i < r) ret[i] = min(r - i, ret[sym]);
		while (i - ret[i] > 0 && i + ret[i] - 1 < len && src[i - ret[i] - 1] == src[i + ret[i] + 1]) ret[i]++;
		if (ret[i] + i > r) r = ret[i] + i, c = i;
	}

	for (int i = 0; i < srcLen; ++i) {
		if (seq[i] != ret[i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int TEST; cin >> TEST; while (TEST--) {
		int L; cin >> L; vector<int> seq(L), res(L, -1);
		string r0, r1, r2, r3; r0 = r1 = r2 = r3 = "";
		bool f0, f1, f2, f3; f0 = f1 = f2 = f3 = false;
		for (int& x : seq) cin >> x;

		res[0] = 0;
		res[1] = 0;

		for (int i = 1; i < L - 1; ++i) {
			if (seq[i] == 0) res[i + 1] = 1 - res[i - 1];
			else res[i + 1] = res[i - 1];
		}

		for (int& x : res) {
			if (x == 0) r0.push_back('0'), r3.push_back('1');
			else r0.push_back('1'), r3.push_back('0');
		}

		res[0] = 0;
		res[1] = 1;

		for (int i = 1; i < L - 1; ++i) {
			if (seq[i] == 0) res[i + 1] = 1 - res[i - 1];
			else res[i + 1] = res[i - 1];
		}

		for (int& x : res) {
			if (x == 0) r1.push_back('0'), r2.push_back('1');
			else r1.push_back('1'), r2.push_back('0');
		}

		if (manacher(seq, r0)) f0 = true;
		if (manacher(seq, r1)) f1 = true;
		if (manacher(seq, r2)) f2 = true;
		if (manacher(seq, r3)) f3 = true;

		cout << f0 + f1 + f2 + f3 << "\n";
		if (f0) cout << r0 << "\n";
		if (f1) cout << r1 << "\n";
		if (f2) cout << r2 << "\n";
		if (f3) cout << r3 << "\n";
		
	}
}