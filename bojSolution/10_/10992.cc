#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n-1; ++i) {
		cout << " ";
	}
	cout << "*\n";
	for (int i = 0; i < n-2; ++i) {
		for (int j = 0; j < n - 2 - i; ++j) cout << " ";
		cout << "*";
		for (int j = 0; j < i*2+1; ++j) cout << " ";
		cout << "*";
		cout << "\n";
	}
	if (n > 1) {
		for (int i = 0; i < n*2-1; ++i) {
			cout << "*";
		}
	}
	cout << "\n";
	return 0;
}