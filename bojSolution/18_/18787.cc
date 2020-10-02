#include <iostream>
#include <algorithm>
using namespace std;

int N;
bool cow[1000];
int lp = -1, rp = -1;

void flip(int l, int r) {
	for (int i = l; i <= r; ++i) cow[i] = !cow[i];
}
void merge(int l, int r) {
	lp = -1; rp = -1;
	for (int i = l; i <= r; ++i) {
		if (cow[i] == 0) {
			if (lp == -1) lp = i;
			rp = i;
		}
	}
}

int res = 0;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		char input; cin >> input;
		cow[i] = (input == 'G' ? true : false);
	}
	for (int i = 0; i < N; ++i) {
		char input; cin >> input;
		bool temp = (input == 'G' ? true : false);
		cow[i] = (cow[i] == temp);
		if (cow[i] == 0) {
			if (lp == -1) lp = i;
			rp = i;
		}
	}
	while (lp != -1 && rp != -1) {
		flip(lp, rp);
		merge(lp, rp);
		res++;
	}

	cout << res;

	return 0;
}