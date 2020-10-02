#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << "1/1";
		return 0;
	}

	int sum = 1; // 분자 + 분모 합
	long long int count = 0; // 각 대각선 시작점
	while (count < n) {
		count += sum;
		sum++;
	}

	int nu = 1, de = 1; // 분자 분모
	if (sum % 2 == 0) {
		de = sum - 1;
	}
	else {
		nu = sum - 1;
	}

	while (count != n) {
		if (sum % 2 == 0) {
			nu++;
			de--;
		}
		else {
			nu--;
			de++;
		}
		count--;
	}
	cout << nu << "/" << de;
	return 0;
}