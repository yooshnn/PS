#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, L, res;
bool spill[1001];

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N >> L;
	for (int i = 1; i <= N; ++i) {
		int input; cin >> input;
		spill[input] = true;
	}

	for (int i = 1; i <= 1000; ++i) {
		if (spill[i]) {
			for (int j = i; j <= min(1000, i + L - 1); ++j) {
				spill[j] = false;
			}
			res++;
		}
	}

	cout << res;

	return 0;
}