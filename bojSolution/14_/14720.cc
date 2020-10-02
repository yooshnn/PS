#include <iostream>
using namespace std;

int N, res;
int cur = -1;
int milk[1000];

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; ++i) cin >> milk[i];


	for (int i = 0; i < N; ++i) {
		if (cur == -1 && milk[i] != 0) continue;
		if (milk[i] == 0 && (cur == -1 || cur == 2)) {
			cur = 0;
			res++;
		}
		else if (milk[i] == 1 && cur == 0) {
			cur = 1;
			res++;
		}
		else if (milk[i] == 2 && cur == 1) {
			cur = 2;
			res++;
		}
	}

	cout << res;

	return 0;
}