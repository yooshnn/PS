#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool seive[1020];

int solve(int n, int k) {
	for (int i = 2; i <= n; ++i) {
		if (seive[i]) continue;
		for (int j = 1; i * j <= n; ++j) {
			if (!seive[i * j]) {
				k -= 1;
				if (k == 0) return i * j;
				seive[i * j] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k; cin >> n >> k;
	cout << solve(n, k);
	
}