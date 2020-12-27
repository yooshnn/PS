#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	vector<int> v(4);
	for (int& x : v) cin >> x;
	sort(v.begin(), v.end());

	int res = 0;

	do {
		if (v[0] < v[2] || v[1] < v[3]) continue;
		res = max(res, v[2] * v[3]);
	} while (next_permutation(v.begin(), v.end()));

	cout << res;

}