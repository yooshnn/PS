#include <bits/stdc++.h>
using namespace std;

int hawk[4];

void doSwap(int i, int j) {
	int t = hawk[i];
	hawk[i] = hawk[j];
	hawk[j] = t;
}
void swap(int i) {
	if (i == 0) doSwap(0, 1);
	if (i == 1) doSwap(0, 2);
	if (i == 2) doSwap(0, 3);
	if (i == 3) doSwap(1, 2);
	if (i == 4) doSwap(1, 3);
	if (i == 5) doSwap(2, 3);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	hawk[0] = 1; hawk[3] = 2;
	string s; cin >> s;
	for (char c : s) {
		swap(c - 'A');
	}
	for (int i = 0; i < 4; ++i) if (hawk[i] == 1) cout << i + 1 << "\n";
	for (int i = 0; i < 4; ++i) if (hawk[i] == 2) cout << i + 1 << "\n";

	return 0;
}