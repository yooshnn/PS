#include <bits/stdc++.h>
using namespace std;

vector<int> str;
vector<int> pal;

void manacher() {
	int c = 0, r = 0;

	for (int i = 0; i < str.size() - 3; ++i) {
		int sym = 2 * c - i;
		if (i < r) pal[i] = min(r - i, pal[sym]);
		while (i - pal[i] > 0 && i + pal[i] - 1 < str.size() && str[i - pal[i] - 1] == str[i + pal[i] + 1]) pal[i] ++;
		if (pal[i] + i > r) {
			r = pal[i] + i; c = i;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, Q; cin >> N; cin.ignore(); cin.clear();

	str.resize(N * 2 + 3, 0);
	pal.resize(N * 2 + 3, 0);
	for (int i = 0; i < N; ++i) cin >> str[1 + i * 2];

	manacher();

	cin >> Q;
	while (Q--) {
		int p, q, center, radius; cin >> p >> q;
		p = p * 2 - 1; q = q * 2 - 1;

		radius = (q - p) / 2;
		center = p + radius;

		cout << (pal[center] >= radius ? 1 : 0) << "\n";
	}

	return 0;
}