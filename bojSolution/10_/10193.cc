#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int TEST; cin >> TEST; while (TEST--) {
		int r = 0;
		string p, q; cin >> p >> q;
		for (int i = 0; i < p.size(); ++i) {
			r += int(p[i]) - int(q[i]);
		}

		cout << "Swapping letters to make " << p << " look like " << q;
		if (r == 0) cout << " was FREE.";
		else if (r < 0) cout << " cost " << -r << " coins.";
		else cout << " earned " << r << " coins.";
		cout << "\n";
	}
}