#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int TEST; cin >> TEST; while (TEST--) {
		string p, q; cin >> p >> q;
		int z = 0, o = 0;
		for (int i = 0; i < p.size(); ++i) {
			if (p[i] != q[i]) (p[i] == '1' ? o : z) += 1;
		}
		cout << max(o, z) << "\n";
	}
}