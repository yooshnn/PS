#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int T, H, W, N;
	cin >> T;

	while (--T >= 0) {
		cin >> H >> W >> N;
		cout << (((N - 1) % H + 1) * 100) + ((N - 1) / H + 1) << "\n";
	}

	return 0;
}