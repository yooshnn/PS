#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 1) cout << "*";
	else {

	for (int i = 0; i < 4 * n - 3; ++i) cout << "*";
	cout << "\n";

	for (int i = 0; i < 2 * (n-1) - 1; ++i) {
		if (i % 2 == 0) {
			for (int j = 0; j < i / 2 + 1; ++j) {
				cout << "* ";
			}
			for (int j = 0; j < 4 * (n-1) - 3 - 2*i; ++j) {
				cout << " ";
			}
			for (int j = 0; j < i / 2 + 1; ++j) {
				cout << " *";
			}
		}
		else {
			for (int j = 0; j < i / 2 + 1; ++j) {
				cout << "* ";
			}
			for (int j = 0; j < 4 * (n - 1) - 3 - 2 * (i-1); ++j) {
				cout << "*";
			}
			for (int j = 0; j < i / 2 + 1; ++j) {
				cout << " *";
			}
		}
		cout << "\n";
	}
	for (int i = 0; i < 4 * n - 3; ++i) {
		if (i % 2 == 0) cout << "*";
		else cout << " ";
	}
	cout << "\n";

	for (int i = 2 * (n - 1) - 1 - 1; i >= 0; --i) {
		if (i % 2 == 0) {
			for (int j = 0; j < i / 2 + 1; ++j) {
				cout << "* ";
			}
			for (int j = 0; j < 4 * (n - 1) - 3 - 2 * i; ++j) {
				cout << " ";
			}
			for (int j = 0; j < i / 2 + 1; ++j) {
				cout << " *";
			}
		}
		else {
			for (int j = 0; j < i / 2 + 1; ++j) {
				cout << "* ";
			}
			for (int j = 0; j < 4 * (n - 1) - 3 - 2 * (i - 1); ++j) {
				cout << "*";
			}
			for (int j = 0; j < i / 2 + 1; ++j) {
				cout << " *";
			}
		}
		cout << "\n";
	}

	for (int i = 0; i < 4 * n - 3; ++i) cout << "*";

	}

	return 0;
}