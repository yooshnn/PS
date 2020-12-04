#include <bits/stdc++.h>
#define y1 Y1
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<ll> line(n);
	ll res = 0;
	for (int i = 0; i < n; ++i) cin >> line[i];
	sort(line.begin(), line.end());
	for (int i = 0; i < n; ++i) {
		if (i != 0) line[i] += line[i - 1];
		res += line[i];
	}
	cout << res;
}