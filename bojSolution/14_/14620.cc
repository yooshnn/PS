#include <bits/stdc++.h>
using namespace std;

int N, res = 2147483647;
int board[10][10];
bool visit[10][10];

int getCost(int r, int c) {
	return board[r][c] + board[r - 1][c] + board[r][c - 1] + board[r + 1][c] + board[r][c + 1];
}

void setVisit(int r, int c, bool tf) {
	visit[r][c] = visit[r - 1][c] = visit[r][c - 1] = visit[r + 1][c] = visit[r][c + 1] = tf;
}

bool getVisit(int r, int c) {
	return visit[r][c] || visit[r - 1][c] || visit[r][c - 1] || visit[r + 1][c] || visit[r][c + 1];
}

void dfs(int flower, int cost, int row, int col) {
	if (flower == 3) {
		res = min(res, cost);
		return;
	}

	for (int r = 1; r < N - 1; ++r) {
		for (int c = 1; c < N - 1; ++c) {
			if (r < row || (r == row && c < col)) continue;
			if (getVisit(r, c)) continue;
			setVisit(r, c, true);
			dfs(flower + 1, cost + getCost(r, c), r, c);
			setVisit(r, c, false);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			cin >> board[r][c];
		}
	}
	for (int r = 1; r < N - 1; ++r) {
		for (int c = 1; c < N - 1; ++c) {
			setVisit(r, c, true);
			dfs(1, getCost(r, c), r, c);
			setVisit(r, c, false);
		}
	}

	cout << res;


	return 0;
}