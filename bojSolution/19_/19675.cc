#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int res;
int sudoku[3][3], on[3][3];

pii pp0(int ir, int ic) {
	for (int r = ir; r < 3; ++r) for (int c = 0; c < 3; ++c) {
		if (r == ir && c <= ic) continue;
		if (on[r][c] == 0) return { r, c };
	}
	return { -1, -1 };
}

vector<bool> pp1(int r, int c) {
	vector<bool> ret(10, false);
	for (int i = 0; i < 3; ++i) {
		ret[on[r][i]] = true;
		ret[on[i][c]] = true;
	}
	return ret;
}

void solve(int ir, int ic) {
	pii next = pp0(ir, ic);
	vector<bool> forbid = pp1(ir, ic);

	for (int i = 1; i <= 9; ++i) {
		if (forbid[i]) continue;
		on[ir][ic] = i;
		if (next.first == -1) res++;
		else solve(next.first, next.second);
		on[ir][ic] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	for (int r = 0; r < 3; ++r) for (int c = 0; c < 3; ++c) {
		cin >> on[r][c];
	}

	for (int r = 0; r < 3; ++r) for (int c = 0; c < 3; ++c) {
		if (on[r][c] == 0) {
			solve(r, c);
			cout << res;
			return 0;
		}
	}

}