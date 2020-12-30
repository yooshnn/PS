#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int TEST; cin >> TEST; while (TEST--) {
		int M; char T; cin >> M >> T;
		for (int i = 0; i < M; ++i) {
			if (T == 'C') {
				char t; cin >> t;
				cout << int(t) - int('A') + 1 << " ";
			}
			else {
				int t; cin >> t;
				cout << char('A' + t - 1) << " ";
			} 
		}
		cout << endl;
	}

}