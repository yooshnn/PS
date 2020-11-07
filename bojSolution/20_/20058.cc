#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, Q, magic;
int res1, res2;
int bfsDir[2][4]{ {0, -1, 0, 1}, {1, 0, -1, 0} };
int board[3][64][64];
bool dup[64][64];

inline int input() {
	int num = 0, ch;
	while ((ch = getchar()) != ' ') {
		if (ch == '\n') break;
		else num = num * 10 + ch - '0';
	}
	return num;
}

void fireStorm(const int& L) {
	int block = pow(2, L);
	magic++;

	for (int r = 0; r < N; r += block) for (int c = 0; c < N; c += block) {
		for (int br = r; br < r + block; ++br) for (int bc = c; bc < c + block; ++bc) {
			board[2][br][bc] = board[1 - magic % 2][(r + block - (bc - c) - 1)][c + (br - r)];
		}
	}

	for (int r = 0; r < N; ++r) for (int c = 0; c < N; ++c) {
		board[magic % 2][r][c] =
			(((r - 1 < 0 || board[2][r - 1][c] == 0) + (c - 1 < 0 || board[2][r][c - 1] == 0) +
				(r + 1 == N || board[2][r + 1][c] == 0) + (c + 1 == N || board[2][r][c + 1] == 0) > 1)
				? max(0, board[2][r][c] - 1) : board[2][r][c]);
	}
}

int bfs(const int& r, const int& c) {
	int ret = 0;
	queue<pii> que;
	for (que.push({ r, c }); !que.empty(); que.pop()) {
		int cr, cc; tie(cr, cc) = que.front();
		for (int i = 0; i < 4; ++i) {
			int nr = cr + bfsDir[0][i], nc = cc + bfsDir[1][i];
			if (nr < 0 || nc < 0 || nr == N || nc == N || dup[nr][nc] || board[magic % 2][nr][nc] == 0) continue;
			dup[nr][nc] = true; ret++;
			que.push({ nr,nc });
		}
	}
	return ret;
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	N = pow(2, input()), Q = input();
	for (int r = 0; r < N; ++r) for (int c = 0; c < N; ++c) board[0][r][c] = input();

	while (Q--) {
		fireStorm(input());
	}

	for (int r = 0; r < N; ++r) for (int c = 0; c < N; ++c) {
		res1 += board[magic % 2][r][c];
		if (board[magic & 2][r][c] != 0) res2 = max(res2, bfs(r, c));
	}
	cout << res1 << "\n" << res2;
}