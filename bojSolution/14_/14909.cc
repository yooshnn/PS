#include <iostream>
using namespace std;
int a;
int main() {
	int res = 0;
	while (cin >> a) {
		if (a > 0) {
			res += 1;
		}
	}
	cout << res;
}