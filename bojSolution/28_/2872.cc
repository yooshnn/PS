#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, p, target, res;
int book[300001];

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> book[i];
	}

	target = N;
	res = 0;

	for (int i = N - 1; i >= 0; --i) {
		if (book[i] == target) target--;
		else res++;
	}

	cout << res;

	return 0;
}