#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

long long N, x;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N >> x;

	long long a, b;
	long long r = 0;
	while (N-- >= 0) {
		cin >> a >> b;
		r *= x;
		r += a;
		r %= 1000000007;
	}

	cout << r;

	return 0;
}