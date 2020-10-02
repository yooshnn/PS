#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int level[101];

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> level[i];
	}

	int limit = level[N], res = 0;
	for (int i = N - 1; i >= 1; --i) {
		if (level[i] >= limit) {
			res += level[i] - limit + 1;
			level[i] = limit - 1;
		}
		limit = level[i];
	}

	cout << res;

	return 0;
}