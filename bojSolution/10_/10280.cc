#include <iostream>
#include <string>
using namespace std;

int n, p;
int lp, rp;
int turn = -1;
string garb;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	cin >> n >> p;
	for (int i = 1; i <= n; ++i) cin >> garb >> garb;

	lp = 1;
	rp = n;
	while (1) {
		//cout << lp << " " << rp << "\n";
		if (lp == rp) {
			if (lp == p) cout << "YES";
			else cout << "NO";
			return 0;
		}
		++turn %= 3;
		if (turn == 0) rp--;
		else if (turn == 1) lp++;
		else {
			if (p - lp >= rp - p) {
				lp++;
			}
			else {
				rp--;
			}
		}
	}

	return 0;
}