#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<char> src(600001, '#');
int pal[600001];

void manacher(int len) {
	int c = 0, r = 0;
	for (int i = 0; i < len; ++i) {
		pal[i] = 0;
		int sym = 2 * c - i;
		if (i < r) pal[i] = min(r - i, pal[sym]);
		while (i - pal[i] > 0 && i + pal[i] - 1 < len && src[i - pal[i] - 1] == src[i + pal[i] + 1]) pal[i]++;
		if (pal[i] + i > r) { r = pal[i] + i; c = i; }
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int TEST; cin >> TEST; while (TEST--) {
		string s; cin >> s;
		fill(src.begin(), src.begin() + s.size() * 2 + 1, '#');
		for (int i = 0; i < s.size(); ++i) src[i * 2 + 1] = s[i];
		manacher(s.size() * 2 + 1);
		ll res = 0;
		for (int i = 0; i < s.size() * 2 + 1; i += 2) {
			int r = pal[i] - pal[i] % 4;
			if (r > res) {
				for (int j = r / 2; j > res / 2; j -= 2) {
					if (pal[i - j] >= j) {
						res = j * 2 - (j * 2) % 4;
						break;
					}
				}
			}
		}
		cout << res << "\n";
	}
	return 0;
}