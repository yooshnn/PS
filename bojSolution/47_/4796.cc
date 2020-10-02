#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int L, P, V;
int res;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	int C = 0;
	while (++C) {
		res = 0;

		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) break;

		res += (V / P) * L;
		res += min(L, V % P);

		cout << "Case " << C << ": " << res << "\n";
	}

	return 0;
}