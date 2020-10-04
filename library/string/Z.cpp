#include <bits/stdc++.h>
using namespace std;

vector<int> Z;

void getZ(string& src) {
	int l = 0, r = 0, len = src.length();
	Z.resize(len);
	for (int i = 1; i < len; i++) {
		Z[i] = max(0, min(Z[i - l], r - i));
		while (src[i + Z[i]] && src[Z[i]] == src[i + Z[i]]) Z[i]++;
		if (i + Z[i] > r) l = i, r = i + Z[i];
	}
	Z[0] = len; // Z[0] = 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string src; cin >> src;
	getZ(src);

	for (auto i : Z) cout << i << " ";

	return 0;
}