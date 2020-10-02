#include <bits/stdc++.h>
using namespace std;

long long L, Ml, Mk, C, penalty;
long long kh = 0, ds = 0;
long long Z[3000002];
queue<int> pd;


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> L >> Ml >> Mk >> C;
	for (int i = 1; i <= L; ++i) cin >> Z[i];

	for (int q = 0; ; q++) {
		ds = min(Mk * Ml, ds + Mk);

		if (!pd.empty()) {
			if (pd.front() == q) pd.pop();
			penalty = Mk * pd.size();
		}

		if (Z[kh + 1] > ds - penalty) {
			if (C > 0) {
				C--;
				penalty += Mk;
				pd.push(kh + Ml);
				Z[kh + 1] = 0;
			}
		}
		if (Z[kh + 1] > ds - penalty) {
			cout << "NO";
			break;
		}
		if (kh == L) {
			cout << "YES";
			break;
		}
		kh++;
	}
	cout << "\n";


	return 0;
}