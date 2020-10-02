#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10001];

void po(int left, int right) {
	if (left >= right) return;
	int sep = upper_bound(arr + left + 1, arr + right, arr[left]) - arr;
	po(left + 1, sep);
	po(sep, right);
	cout << arr[left] << "\n";
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	int N, i = 0;
	while (cin >> N) {
		arr[i++] = N;
	}
	po(0, i);

	return 0;
}