#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int a[100], n;
	bool goodJob = true;
	
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];

	for (int i = 1; i <= a[n - 1]; ++i) {
		if (find(a, a + n, i) - a == n) {
			cout << i << "\n"; goodJob = false;
		}
	}
	if (goodJob) cout << "good job";

	return 0;
}