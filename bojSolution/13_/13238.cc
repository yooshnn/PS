#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, res;
int coin[10001];

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> coin[i];
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = i; j <= N; ++j) {
			if (coin[j] - coin[i] > res) res = coin[j] - coin[i];
		}
	}

	cout << res;

	return 0;
}