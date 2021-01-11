#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;

int getZ(string src) {
	int l = 0, r = 0, len = src.length();
	vector<int> Z(len);
	for (int i = 1; i < len; i++) {
		Z[i] = max(0, min(Z[i - l], r - i));
		while (src[i + Z[i]] && src[Z[i]] == src[i + Z[i]]) Z[i]++;
		if (i + Z[i] > r) l = i, r = i + Z[i];
	}
	Z[0] = 0;
	return *max_element(Z.begin(), Z.end());
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	string s, t;
	cin >> s >> t;
	cout << max(getZ(s+'@'+t), getZ(t+'@'+s));

    return_0;
}