#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t[4][2];
	cin >> t[0][0] >> t[0][1] >> t[1][0] >> t[1][1] >> t[2][0] >> t[2][1] >> t[3][0] >> t[3][1];
	
	int p[4];
	p[0] = t[0][1];
	p[1] = p[0] - t[1][0] + t[1][1];
	p[2] = p[1] - t[2][0] + t[2][1];
	p[3] = p[2] - t[3][0];

	cout << max(max(max(p[0], p[1]),p[2]),p[3]);
	return 0;
}
