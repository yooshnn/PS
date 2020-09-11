#include <bits/stdc++.h>
using namespace std; int TEST;

int n;
int a, b, at, bt;
int candy[1000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin >> TEST;

	while (TEST--) {
		a = b = at = bt = 0;

		cin >> n;
		cin >> a; // Alice begins
		for (int i = 1; i < n; ++i) cin >> candy[i];
		int lp = 1, rp = n - 1, cnt = 1;

		while (1) {
			while (b <= a && rp >= lp) {
				b += candy[rp--];
			} 
			if (b != 0) cnt++;
			at += a; a = 0;
			if (lp > rp) {
				bt += b;
				break;
			}

			while (a <= b && lp <= rp) {
				a += candy[lp++];
			}
			if (a != 0) cnt++;
			bt += b; b = 0;
			if (lp > rp) {
				at += a;
				break;
			}
			//cout << "TURN " << cnt << " : RP " << rp << " LP " << lp << " a " << a << " b " << b << "\n";
		}

		cout << cnt << " " << at << " " << bt << "\n";

	}

	return 0;
}