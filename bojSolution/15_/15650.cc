#include <iostream>
using namespace std;

int a[9];
bool sel[9]{ false, };

void selm(int);

int lim, siz;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> lim >> siz;

	selm(1);


	return 0;
}

void selm(int depth) {
	if (depth > siz) {
		for (int i = 1; i <= siz; ++i) {
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= lim; ++i) {
		if (sel[i] == true) continue;
		if (i < a[depth - 1]) continue;
		sel[i] = true;
		a[depth] = i;
		selm(depth + 1);
		sel[i] = false;
	}
}