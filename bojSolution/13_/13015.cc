#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	// 첫 줄
	for (int i = 0; i < n; ++i)	cout << "*";
	for (int i = 0; i < 1+(n-2)*2; ++i)	cout << " ";
	for (int i = 0; i < n; ++i)	cout << "*";

	cout << "\n";

	// 2 ~ n-1째 줄
	for (int i = 0; i < n-2; ++i) {
		for (int j = 0; j <= i; ++j) cout << " ";
		cout << "*";
		for (int j = 0; j < n - 2; ++j) cout << " ";
		cout << "*";
		for (int j = 0; j < 1 + (n - 2) * 2 - 2 * (i+1); ++j) cout << " ";
		cout << "*";
		for (int j = 0; j < n - 2; ++j) cout << " ";
		cout << "*";

		cout << "\n";
	}

	// 가운데 삼성
	for (int i = 0; i < n - 1; ++i) cout << " ";
	cout << "*";
	for (int j = 0; j < n - 2; ++j) cout << " ";
	cout << "*";
	for (int j = 0; j < n - 2; ++j) cout << " ";
	cout << "*";

	cout << "\n";

	for (int i = n - 3; i >= 0; --i) {
		for (int j = 0; j <= i; ++j) cout << " ";
		cout << "*";
		for (int j = 0; j < n - 2; ++j) cout << " ";
		cout << "*";
		for (int j = 0; j < 1 + (n - 2) * 2 - 2 * (i + 1); ++j) cout << " ";
		cout << "*";
		for (int j = 0; j < n - 2; ++j) cout << " ";
		cout << "*";

		cout << "\n";
	}

	for (int i = 0; i < n; ++i)	cout << "*";
	for (int i = 0; i < 1 + (n - 2) * 2; ++i)	cout << " ";
	for (int i = 0; i < n; ++i)	cout << "*";

	return 0;
}