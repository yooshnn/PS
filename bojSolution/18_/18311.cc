#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll course[100010];
ll psum1[100010], psum2[100010];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, k; cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> course[i];
	psum1[0] = course[0], psum2[0] = course[n - 1];
	for (int i = 1; i < n; ++i) {
		psum1[i] = course[i] + psum1[i - 1];
		psum2[i] = course[n - 1 - i] + psum2[i - 1];
	}

	int req = upper_bound(psum1, psum1 + n, k) - psum1;
	if (req != n) {
		cout << 1 + req;
	}
	else {
		req = upper_bound(psum2, psum2 + n, k - psum1[n - 1]) - psum2;
		cout << n - req;
	}
}