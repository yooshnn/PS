#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T, N;
	cin >> T;
	while (T-- > 0) {
		int res = 0;
		int A, B, C;
		cin >> N;
		for (int i = 1; i <= N; ++i) {
			cin >> A >> B >> C;
			res += max(0, max(C, max(A, B)));
		}
		cout << res << "\n";
	}

	return 0;
}