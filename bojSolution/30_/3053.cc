#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int r;
	cin >> r;
	cout << fixed << setprecision(10) << r * r * 3.141592653589793238462643383279502884197 << "\n";
	cout << pow(2 * r, 2) / 2;

	return 0;
}