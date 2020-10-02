#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct P;

int R, C;
char board[10][10];
typedef struct P {
	int r = -1, c = -1;
	P() {}
	P(int R, int C) { r = R, c = C; }
	void S(int R, int C) { r = R; c = C; }
	bool C(int R, int C) { return (r == R && c == C); }
	bool escCheck() {
		return (board[r][c] == 'O');
	}
} P;
P red, blue;

bool movable(int r, int c, bool isRed) {
	if (isRed) {
		if (red.r == -1) return false;
		return (board[red.r + r][red.c + c] == '.' || board[red.r + r][red.c + c] == 'O') && !(blue.C(red.r + r, red.c + c));
	}
	else return (board[blue.r + r][blue.c + c] == '.' || board[blue.r + r][blue.c + c] == 'O') && !(red.C(blue.r + r, blue.c + c));
}

int rot(int dir) {
	int flag = 0;
	if (dir == 0) {
		if (blue.c >= red.c) {
			while (movable(0, 1, false)) {
				blue.c += 1;
				if (blue.escCheck()) { flag = -99; break; }
			}
			while (movable(0, 1, true)) {
				red.c += 1;
				if (red.escCheck()) { if (flag == 0) flag = 1; red.r = -1; }
			}
		}
		else {
			while (movable(0, 1, true)) {
				red.c += 1;
				if (red.escCheck()) { if (flag == 0) flag = 1; red.r = -1; }
			}
			while (movable(0, 1, false)) {
				blue.c += 1;
				if (blue.escCheck()) { flag = -99; break; }
			}
		}
	}
	else if (dir == 180) {
		if (blue.c <= red.c) {
			while (movable(0, -1, false)) {
				blue.c -= 1;
				if (blue.escCheck()) { flag = -99; break; }
			}
			while (movable(0, -1, true)) {
				red.c -= 1;
				if (red.escCheck()) { if (flag == 0) flag = 1; red.r = -1; }
			}
		}
		else {
			while (movable(0, -1, true)) {
				red.c -= 1;
				if (red.escCheck()) { if (flag == 0) flag = 1; red.r = -1; }
			}
			while (movable(0, -1, false)) {
				blue.c -= 1;
				if (blue.escCheck()) { flag = -99; break; }
			}
		}
	}
	else if (dir == 90) {
		if (blue.r <= red.r) {
			while (movable(-1, 0, false)) {
				blue.r -= 1;
				if (blue.escCheck()) { flag = -99; break; }
			}
			while (movable(-1, 0, true)) {
				red.r -= 1;
				if (red.escCheck()) { if (flag == 0) flag = 1; red.r = -1; }
			}
		}
		else {
			while (movable(-1, 0, true)) {
				red.r -= 1;
				if (red.escCheck()) { if (flag == 0) flag = 1; red.r = -1; }
			}
			while (movable(-1, 0, false)) {
				blue.r -= 1;
				if (blue.escCheck()) { flag = -99; break; }
			}
		}
	}
	else if (dir == 270) {
		if (blue.r >= red.r) {
			while (movable(1, 0, false)) {
				blue.r += 1;
				if (blue.escCheck()) { flag = -99; break; }
			}
			while (movable(1, 0, true)) {
				red.r += 1;
				if (red.escCheck()) { if (flag == 0) flag = 1; red.r = -1; }
			}
		}
		else {
			while (movable(1, 0, true)) {
				red.r += 1;
				if (red.escCheck()) { if (flag == 0) flag = 1; red.r = -1; }
			}
			while (movable(1, 0, false)) {
				blue.r += 1;
				if (blue.escCheck()) { flag = -99; break; }
			}
		}
	}
	/*if (flag != 0) {
		cout << flag << " ";
	}*/
	if (flag == 1) return 1;
	else if (flag == 0) return 0;
	else return -1;
}

int dfs(int depth) {
	if (depth == 11) return 100;
	int ret = 100;

	P redOrg{ red.r, red.c }, blueOrg{ blue.r, blue.c };
	for (int i = 0; i < 4; ++i) {
		int req = rot(i * 90);
		if (req == 1) {
			return depth;
		}
		if (req == 0) {
			ret = min(ret, dfs(depth + 1));
		}
		red.S(redOrg.r, redOrg.c); blue.S(blueOrg.r, blueOrg.c);
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R >> C;
	for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
		cin >> board[r][c];
		if (board[r][c] == 'R') {
			red.S(r, c); // should escape
			board[r][c] = '.';
		}
		if (board[r][c] == 'B') {
			blue.S(r, c); // should stay
			board[r][c] = '.';
		}
	}

	int req = dfs(1);
	cout << (req == 100 ? -1 : req) << "\n";

	/*while (1) {
		int d = 0; cin >> d;
		rot(d * 90);
		for (int r = 0; r < R; ++r) {
			for (int c = 0; c < C; ++c) {
				if (r == red.r && c == red.c) cout << "R";
				else if (r == blue.r && c == blue.c) cout << "B";
				else cout << board[r][c];
			}cout << "\n";
		}cout << "\n";
	}*/




	return 0;
}

