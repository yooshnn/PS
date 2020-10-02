#include <iostream>
#include <algorithm>
using namespace std;

int D, N;
int oven[300001];
int in, res;

int main() {
	cin >> D >> N;
	for (int i = D - 1; i >= 0; --i) {
		cin >> oven[i];
		if (i == D - 1) continue;
		if (oven[i] > oven[i + 1]) oven[i] = oven[i + 1];
	}

	for (int i = 1; i <= N; ++i) {
		cin >> in;
		res = lower_bound(oven + res, oven + D, in) - oven;
		if (res >= D) {
			res = D + 1;
			break;
		}
		res++;
	}
	cout << D + 1 - res;

	return 0;
}