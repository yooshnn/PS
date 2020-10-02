#include <iostream>
#include <cstring>
using namespace std;

int N, S, R;
int kayak[12];

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	memset(kayak, -1, sizeof(kayak));

	cin >> N >> S >> R;

	for (int i = 1; i <= N; ++i) kayak[i] = 1;

	for (int i = 0; i < S; ++i) {
		int input; cin >> input;
		kayak[input] = 0;
	}

	for (int i = 0; i < R; ++i) {
		int input; cin >> input;
		kayak[input] += 1;
	}

	// kayak 0 : broken 1: ready 2: extra

	int res = 0;

	for (int i = 1; i <= N; ++i) {
		if (kayak[i] == 0) {
			if (kayak[i - 1] == 2) {
				kayak[i] = 1;
				kayak[i - 1] = 1;
				res++;
			}
			else if (kayak[i + 1] == 2) {
				kayak[i] = 1;
				kayak[i + 1] = 1;
				res++;
			}
		}
		else if (kayak[i] >= 1) {
			res++;
		}
	}

	cout << N - res;
	
	return 0;
}