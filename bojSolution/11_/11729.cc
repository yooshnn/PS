#include <iostream>
#include <math.h>
using namespace std;

void hanoi(int, int, int, int);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;
	cout << fixed << (int)pow(2, N) - 1 << "\n";
	hanoi(N, 1, 2, 3);

	return 0;
}

void hanoi(int n, int a, int b, int c) {
	if (n == 1) {
		cout << a << " " << c << "\n";
		return;
	}
	hanoi(n - 1, a, c, b);
	cout << a << " " << c << "\n";
	hanoi(n - 1, b, a, c);
}