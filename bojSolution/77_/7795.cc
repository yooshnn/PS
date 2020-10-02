#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int TEST; cin >> TEST; while (TEST--) {
		int A, B; cin >> A >> B;
		vector<int> a(A), b(B);
		for (int i = 0; i < A; ++i) cin >> a[i]; sort(a.begin(), a.end());
		for (int i = 0; i < B; ++i) cin >> b[i]; sort(b.begin(), b.end());

		ll res = 0;
		for (int i : a) {
			res += 1LL * (lower_bound(b.begin(), b.end(), i) - b.begin());
		}
		cout << res << "\n";
	}

	return 0;
}