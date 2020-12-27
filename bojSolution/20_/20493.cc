#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	ll row = 0, col = 0;

	ll N, T, lt = 0, dir = 0;
	cin >> N >> T;

	int t; string d;
	for (int i = 0; i < N; ++i) {
		cin >> t >> d;

		if (dir == 0) col += t - lt;
		else if (dir == 1) row -= t - lt;
		else if (dir == 2) col -= t - lt;
		else row += t - lt;

		if (d == "right") dir = (dir + 3) % 4;
		if (d == "left") dir = (dir + 1) % 4;

		lt = t;
	}

	if (dir == 0) col += T - lt;
	else if (dir == 1) row -= T - lt;
	else if (dir == 2) col -= T - lt;
	else row += T - lt;

	cout << col << " " << -row;
}