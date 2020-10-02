#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
int p[1000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for (int m = 0; m < M; ++m) cin >> p[m];
	sort(p, p + M);

	int r = 0, profit = 0;
	for (int i = 0; i < M; ++i) {
		if (min(N, M - i) * p[i] > profit) {
			profit = min(N, M - i) * p[i];
			r = p[i];
		}
	}

	cout << r << " " << profit;

	return 0;
}