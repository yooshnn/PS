#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int res = 0, pos = -1;
	int n; cin >> n;
	vector<int> v(n), w(n, 0), p(n, -1), r;
	for (int i = 0; i < n; ++i) cin >> v[i];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (v[i] > v[j] && w[i] <= w[j]) {
				w[i] = w[j] + 1;
				p[i] = j;
				if (w[i] > res) {
					pos = i; res = w[i];
				}
			}
		}
	}

	cout << res + 1 << "\n";
	while (res != 0) {
		r.push_back(v[pos]);
		if (p[pos] == -1) break;
		pos = p[pos];
	}
	if (res == 0) r.push_back(v[0]);
	for (int i = r.size() - 1; i >= 0; --i) cout << r[i] << " ";

}