#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	if (A == B && A == C && B == C) {
		cout << 10000 + A * 1000;
	}
	else if (A != B && A != C && B != C) {
		cout << 100 * max(C, max(A, B));
	}
	else {
		if (A == B || A == C) cout << 1000 + 100 * A;
		else cout << 1000 + 100 * B;
	}

	return 0;
}