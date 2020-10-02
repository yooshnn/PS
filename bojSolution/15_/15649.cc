#include <iostream>
using namespace std;

int a[9];
bool sel[9]{ false, };

void selm(int, int, int);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	selm(n, m, 1);


	return 0;
}

void selm(int lim, int size, int depth) {
	if (depth > size) {
		for (int i = 1; i <= size; ++i) {
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= lim; ++i) {
		if (sel[i] == true) continue;
		sel[i] = true;
		a[depth] = i;
		selm(lim, size, depth + 1);
		sel[i] = false;
	}
}