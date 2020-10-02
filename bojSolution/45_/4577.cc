#include <bits/stdc++.h>
using namespace std;

int R, C;
int pr, pc;
int boxCnt;
char board[15][15];
string key;

char g(int r, int c) { return board[r][c]; }
void s(int r, int c, char val) { board[r][c] = val; }

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int GAME = 0;
	while (++GAME) {
		boxCnt = 0;

		cin >> R >> C;
		if (C == 0) break;
		for (int r = 0; r < R; ++r) {
			for (int c = 0; c < C; ++c) {
				cin >> board[r][c];
				if (g(r, c) == 'w' || g(r, c) == 'W') {
					pr = r, pc = c;
					s(r, c, (g(r, c) == 'w' ? '.' : '+'));
				}
				if (g(r, c) == 'b') boxCnt++;
			}
		}
		cin >> key;

		for (char k : key) {
			if (boxCnt == 0) break;
			if (k == 'U') {
				if (g(pr - 1, pc) == '.') pr--;
				else if (g(pr - 1, pc) == 'b' || g(pr - 1, pc) == 'B') {
					if (g(pr - 2, pc) == '.') {
						if (g(pr - 1, pc) == 'B') boxCnt++;
						s(pr - 1, pc, g(pr - 1, pc) == 'b' ? '.' : '+');
						s(pr - 2, pc, 'b');
						pr--;
					}
					else if (g(pr - 2, pc) == '+') {
						if (g(pr - 1, pc) == 'b') boxCnt--;
						s(pr - 1, pc, g(pr - 1, pc) == 'b' ? '.' : '+');
						s(pr - 2, pc, 'B');
						pr--;
					}
				}
			}
			else if (k == 'D') {
				if (g(pr + 1, pc) == '.') pr++;
				else if (g(pr + 1, pc) == 'b' || g(pr + 1, pc) == 'B') {
					if (g(pr + 2, pc) == '.') {
						if (g(pr + 1, pc) == 'B') boxCnt++;
						s(pr + 1, pc, g(pr + 1, pc) == 'b' ? '.' : '+');
						s(pr + 2, pc, 'b');
						pr++;
					}
					else if (g(pr + 2, pc) == '+') {
						if (g(pr + 1, pc) == 'b') boxCnt--;
						s(pr + 1, pc, g(pr + 1, pc) == 'b' ? '.' : '+');
						s(pr + 2, pc, 'B');
						pr++;
					}
				}
			}
			else if (k == 'L') {
				if (g(pr, pc - 1) == '.') pc--;
				else if (g(pr, pc - 1) == 'b' || g(pr, pc - 1) == 'B') {
					if (g(pr, pc - 2) == '.') {
						if (g(pr, pc - 1) == 'B') boxCnt++;
						s(pr, pc - 1, g(pr, pc - 1) == 'b' ? '.' : '+');
						s(pr, pc - 2, 'b');
						pc--;
					}
					else if (g(pr, pc - 2) == '+') {
						if (g(pr, pc - 1) == 'b') boxCnt--;
						s(pr, pc - 1, g(pr, pc - 1) == 'b' ? '.' : '+');
						s(pr, pc - 2, 'B');
						pc--;
					}
				}
			}
			else if (k == 'R') {
				if (g(pr, pc + 1) == '.') pc++;
				else if (g(pr, pc + 1) == 'b' || g(pr, pc + 1) == 'B') {
					if (g(pr, pc + 2) == '.') {
						if (g(pr, pc + 1) == 'B') boxCnt++;
						s(pr, pc + 1, g(pr, pc + 1) == 'b' ? '.' : '+');
						s(pr, pc + 2, 'b');
						pc++;
					}
					else if (g(pr, pc + 2) == '+') {
						if (g(pr, pc + 1) == 'b') boxCnt--;
						s(pr, pc + 1, g(pr, pc + 1) == 'b' ? '.' : '+');
						s(pr, pc + 2, 'B');
						pc++;
					}
				}
			}
		}
		cout << "Game " << GAME << ": " << (boxCnt == 0 ? "complete" : "incomplete") << "\n";
		for (int r = 0; r < R; ++r) {
			for (int c = 0; c < C; ++c) {
				if (r == pr && c == pc) {
					if (board[r][c] == '.') cout << 'w';
					if (board[r][c] == '+') cout << 'W';
				}
				else cout << board[r][c];
			}
			cout << "\n";
		}

	}

	return 0;
}