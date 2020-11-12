#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, cnt;
void solve(int depth, int len, int l, ll v) {
	if (N == -1) return;
	if (depth == len) {
		cnt += 1;
		if (cnt == N) {
			N = -1;
			cout << v;
		}
		return;
	}
	for (int i = 0; i < l; ++i) {
		solve(depth + 1, len, i, v * 10 + i);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N; N--;
	if (N == 0) {
		cout << 0; return 0;
	}
	if (N > 1022) {
		cout << -1; return 0;
	}


	for (int len = 1; len <= 10; ++len) {
		for (int i = 1; i <= 9; ++i) {
			if (N == -1) return 0;
			solve(1, len, i, i);
		}
	}
}