#include <iostream>
using namespace std;

int main() {
	int L, P, ans;
	cin >> L >> P;
	ans = L * P;

	int news[5];
	cin >> news[0] >> news[1] >> news[2] >> news[3] >> news[4];

	cout << news[0] - ans << " " << news[1] - ans << " " << news[2] - ans << " " << news[3] - ans << " " << news[4] - ans;

	return 0;
}