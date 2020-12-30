#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int N, M, K; cin >> N >> M >> K; M *= K;
	int p[N]; for (int& x : p) cin >> x;
	sort(&p[0], &p[0] + N);

	int i = N - 1;
	while (i >= 0 && M > 0) {
		M -= p[i];
		i--;
	}
	if (M <= 0) cout << N - 1 - i;
	else cout << "STRESS";

}