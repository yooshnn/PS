#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
bool g;
bool cow[1000000];
int lp, rp;

void flip(int l, int r) {
	for (int i = l; i <= r; ++i) cow[i] = !cow[i];
}
void merge(int l, int r) {
	lp = -1; rp = -1;
	for (int i = l; i <= r; ++i) {
		if (cow[i] == g) {
			if (lp == -1) lp = i;
			rp = i;
		}
	}
}

int res = 0;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	string input; getline(cin, input);  int N = input.size();
	for (int i = 0; i < N; ++i) {
		cow[i] = (input[i] == '1' ? 1 : 0);
	} lp = 0; rp = N;
	if (cow[0] == 0) {
		g = true;
		while (cow[++lp] == 0) {
			if (lp >= N - 1) { lp = -1; break; }
		}
		while (cow[--rp] == 0) {
			if (rp <= 0) { rp = -1; break; }
		}
	}
	else {
		g = false;
		while (cow[++lp] == 1) {
			if (lp >= N - 1) { lp = -1; break; }
		}
		while (cow[--rp] == 1) {
			if (rp <= 0) { rp = -1; break; }
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