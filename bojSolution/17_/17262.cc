#include <iostream>
#include <algorithm>
using namespace std;

int N;
int ef = 100001, sl = -1;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		int s, e; cin >> s >> e;
		if (s > sl) sl = s;
		if (e < ef) ef = e;
	}

	cout << max(0, sl - ef);

	return 0;
}