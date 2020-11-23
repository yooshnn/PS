#include <bits/stdc++.h>
using namespace std;

string src, tar;
vector<int> fail, KMP;

char board[102][102];

vector<int> getFail(string t) {
	vector<int> ret(t.length());
	int j = 0;
	for (int i = 1; i < t.length(); ++i) {
		while (j > 0 && t[i] != t[j]) j = ret[j - 1];
		if (t[i] == t[j]) ret[i] = ++j;
	}

	return ret;
}

bool getKMP(string s, string t) {
	vector<int> ret;
	fail = getFail(t);
	int sLen = s.length(), tLen = t.length(), j = 0;

	for (int i = 0; i < sLen; ++i) {
		while (j > 0 && s[i] != t[j]) j = fail[j - 1];
		if (s[i] == t[j]) {
			if (j == tLen - 1) {
				return true;
			}
			else j++;
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fill(&board[0][0], &board[0][0] + 102 * 102, '#');

	cin >> tar;
	int R, C; cin >> R >> C;
	for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) cin >> board[r][c];

	for (int r = 1; r <= R; ++r) for (int c = 0; c < C + 1; ++c) {
		src.push_back(board[r][c]);
	}
	for (int r = 1; r <= R; ++r) for (int c = C + 1; c > 0; --c) {
		src.push_back(board[r][c]);
	}
	for (int c = 1; c <= C; ++c) for (int r = 0; r < R + 1; ++r) {
		src.push_back(board[r][c]);
	}
	for (int c = 1; c <= C; ++c) for (int r = R + 1; r >=0; --r) {
		src.push_back(board[r][c]);
	}

	int br = 0, bc = C - 1;
	while (1) {
		int cr = br, cc = bc;
		while (cc <= C && cr <= R) {
			src.push_back(board[cr][cc]);
			cr += 1; cc += 1;
		}
		if (bc != 0) bc -= 1;
		else br += 1;
		if (br == R) break;
	}
	br = R + 1, bc = 2;
	while (1) {
		int cr = br, cc = bc;
		while (cc >= 1 && cr >= 1) {
			src.push_back(board[cr][cc]);
			cr -= 1; cc -= 1;
		}
		if (bc != C + 1) bc += 1;
		else br -= 1;
		if (br == 1) break;
	}
	br = 0, bc = 2;
	while (1) {
		int cr = br, cc = bc;
		while (cc >= 1 && cr <= R) {
			src.push_back(board[cr][cc]);
			cr += 1; cc -= 1;
		}
		if (bc != C + 1) bc += 1;
		else br += 1;
		if (br == R) break;
	}
	br = 2, bc = 0;
	while (1) {
		int cr = br, cc = bc;
		while (cc <= C && cr >= 1) {
			src.push_back(board[cr][cc]);
			cr -= 1; cc += 1;
		}
		if (br != R + 1) br += 1;
		else bc += 1;
		if (bc == C) break;
	}


	cout << (getKMP(src, tar) ? 1 : 0);

	return 0;
}