#include <iostream>
using namespace std;

int main() {
	bool flag = false;
	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i) {
		int temp = i;
		for (int j = i; j > 0; j /= 10) {
			temp += j % 10;
		}
		if (temp == N) { cout << i; flag = true; break; }
	}
	if (!flag) cout << 0;
	return 0;
}