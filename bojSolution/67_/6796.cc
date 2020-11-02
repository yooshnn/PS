#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<char, int> M;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (1) {
		int oper, q;
		char p, pp;
		cin >> oper;
		if (oper == 1) {
			cin >> p >> q;
			M[p] = q;
		}
		else if (oper == 2) {
			cin >> p;
			cout << M[p] << "\n";
		}
		else if (oper == 3) {
			cin >> p >> pp;
			M[p] = M[p] + M[pp];
		}
		else if (oper == 4) {
			cin >> p >> pp;
			M[p] = M[p] * M[pp];
		}
		else if (oper == 5) {
			cin >> p >> pp;
			M[p] = M[p] - M[pp];
		}
		else if (oper == 6) {
			cin >> p >> pp;
			M[p] = M[p] / M[pp];
		}
		else break;
	}
	return 0;
}