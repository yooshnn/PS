#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	string t[7] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
	int m, d;

	cin >> m >> d;
	for (int i = 1; i < m; ++i) {
		d += n[i - 1];
	}

	cout << t[d % 7];

	return 0;
}
