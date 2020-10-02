#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M;

int solve() {
	if (N == 1 || M == 1) return 1;
	if (N == 2) return min(4, (M + 1) / 2);
	return min(4, M);
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N >> M;

	if (N >= 3 && M >= 7) {
		cout << M - 2;
	}
	else {
		cout << solve();
	}

	return 0;
}