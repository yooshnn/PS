#include <bits/stdc++.h>
using namespace std;

struct pos {
	int r, c;
	void set(int R, int C) { r = R; c = C; }
	bool get(int R, int C) { return (r == R && c == C); }
};
int board[1000][1000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	pos SK, PROF;

	int N; cin >> N;
	for (int r = 0; r < N; ++r) for (int c = 0; c < N; ++c) {
		cin >> board[r][c];
		if (board[r][c] == 2) SK.set(r, c);
		if (board[r][c] == 5) PROF.set(r, c);
	}

	double dist = sqrt((SK.r - PROF.r) * (SK.r - PROF.r) + (SK.c - PROF.c) * (SK.c - PROF.c));
	int cnt = 0;

	if (dist < 5) cout << 0;
	else {
		for (int r = min(SK.r, PROF.r); r <= max(SK.r, PROF.r); ++r) {
			for (int c = min(SK.c, PROF.c); c <= max(SK.c, PROF.c); ++c) {
				if (SK.get(r, c) || PROF.get(r, c)) continue;
				if (board[r][c] == 1) cnt++;
			}
		}
		cout << (cnt >= 3 ? 1 : 0);
	}
}