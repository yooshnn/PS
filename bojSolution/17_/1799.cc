#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, resB, resW;
int visit[10][10];
bool board[10][10];

void bishopPlace(int r, int c) {
	for (int i = 0; i < N; ++i) {
		if (i == 0) {
			visit[r][c] += 1; continue;
		}
		if (r + i < N && c + i < N) visit[r + i][c + i] += 1;
		if (r + i < N && c - i >= 0) visit[r + i][c - i] += 1;
		if (r - i >= 0 && c + i < N) visit[r - i][c + i] += 1;
		if (r - i >= 0 && c - i >= 0) visit[r - i][c - i] += 1;
	}
}
void bishopRemove(int r, int c) {
	for (int i = 0; i < N; ++i) {
		if (i == 0) {
			visit[r][c] -= 1; continue;
		}
		if (r + i < N && c + i < N) visit[r + i][c + i] -= 1;
		if (r + i < N && c - i >= 0) visit[r + i][c - i] -= 1;
		if (r - i >= 0 && c + i < N) visit[r - i][c + i] -= 1;
		if (r - i >= 0 && c - i >= 0) visit[r - i][c - i] -= 1;
	}
}

void dfsB(int depth, int ir, int ic) {
	bool fail = true;
	for (int r = ir; r < N; ++r) {
		for (int c = (r == ir ? ic + 2 : r%2); c < N; c += 2) {
			if (board[r][c] && visit[r][c] == 0) {
				fail = false;
				bishopPlace(r, c);
				dfsB(depth + 1, r, c);
				bishopRemove(r, c);
			}
		}
	}
	if (fail) {
		resB = max(resB, depth);
	}
}
void dfsW(int depth, int ir, int ic) {
	bool fail = true;
	for (int r = ir; r < N; ++r) {
		for (int c = (r == ir ? ic + 2 : 1 - r % 2); c < N; c += 2) {
			if (board[r][c] && visit[r][c] == 0) {
				fail = false;
				bishopPlace(r, c);
				dfsW(depth + 1, r, c);
				bishopRemove(r, c);
			}
		}
	}
	if (fail) {
		resW = max(resW, depth);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int r = 0; r < N; ++r) for (int c = 0; c < N; ++c) cin >> board[r][c];
	for (int r = 0; r < N; ++r) for (int c = r%2; c < N; c += 2) if (board[r][c]) {
		bishopPlace(r, c);
		dfsB(1, r, c);
		bishopRemove(r, c);
	}
	for (int r = 0; r < N; ++r) for (int c = 1 - r % 2; c < N; c += 2) if (board[r][c]) {
		bishopPlace(r, c);
		dfsW(1, r, c);
		bishopRemove(r, c);
	}

	cout << resB + resW;



	return 0;
}