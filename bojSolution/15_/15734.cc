#include <iostream>
#include <algorithm>

using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int L, R, A;
	cin >> L >> R >> A;

	if (L == R) {
		cout << (L + A / 2) * 2;
	}
	else {
		while (1) {
			if ((A == 0) || (A == 1 && L == R)) break;
			A--;
			if (L > R) R++;
			else L++;
		}
		if (L == R) {
			cout << L + R;
		}
		else {
			cout << min(L, R) * 2;
		}
	}

	return 0;
}