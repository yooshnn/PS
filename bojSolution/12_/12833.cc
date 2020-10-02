#include <iostream>
using namespace std;

int a, b, c, r;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> a >> b >> c;
	r = (a ^ b);
	while (--c) {
		r = (r ^ b);
	}
	cout << r;

	return 0;
}