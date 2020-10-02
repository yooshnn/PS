#include <bits/stdc++.h>
using namespace std;

int n, p, l, f, res;
stack<int> fret[7];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> p;
	while (n--) {
		cin >> l >> f;

		while (!fret[l].empty() && fret[l].top() > f) {
			fret[l].pop();
			res++;
		}
		if (!fret[l].empty() && fret[l].top() == f) continue;
		res++;
		fret[l].push(f);
	}

	cout << res;

	return 0;
}