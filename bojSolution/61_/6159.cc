#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, s; cin >> n >> s;
	vector<int> cow(n); for (int& x : cow) cin >> x; sort(cow.begin(), cow.end());
	int res = 0;
	for (int i = 1; i < n; ++i) {
		res += upper_bound(cow.begin(), cow.begin() + i, s - cow[i]) - cow.begin();
	}
	cout << res << "\n";
}