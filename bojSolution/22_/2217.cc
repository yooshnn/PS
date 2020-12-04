#include <bits/stdc++.h>
#define y1 Y1
using namespace std;
typedef long long ll;

ll rope[100000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> rope[i];
	sort(rope, rope + n);
	reverse(rope, rope + n);

	ll res = 0;
	for (ll i = 0; i < n; ++i) {
		res = max(res, (i + 1) * rope[i]);
	}
	cout << res;
}