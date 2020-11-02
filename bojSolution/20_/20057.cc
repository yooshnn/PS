#include <bits/stdc++.h>
using namespace std;

int N, res = 0;
int board[500][500];

bool inBoard(int r, int c) {
	return !(r < 0 || c < 0 || r >= N || c >= N);
}
int fly(int r, int c, int ra, int ca, double p) {
	int ret = double(board[r][c]) * p;

	if (inBoard(ra, ca)) board[ra][ca] += ret;
	else res += ret;

	return ret;
}

struct Tor {
	int r, c, d, s, t;

	Tor(int N) {
		r = c = N / 2;
		d = 2;
		s = t = 1;
	}
	void run() {
		int tot = 0;

		/*cout << r << " " << c << "\n";
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}*/

		if (d == 0) { c += 1;
			tot += fly(r, c, r, c + 2, 0.05);
			tot += fly(r, c, r + 1, c + 1, 0.10);
			tot += fly(r, c, r - 1, c + 1, 0.10);
			tot += fly(r, c, r - 2, c, 0.02);
			tot += fly(r, c, r - 1, c, 0.07);
			tot += fly(r, c, r + 1, c, 0.07);
			tot += fly(r, c, r + 2, c, 0.02);
			tot += fly(r, c, r + 1, c - 1, 0.01);
			tot += fly(r, c, r - 1, c - 1, 0.01);

			if (inBoard(r, c + 1)) board[r][c + 1] += board[r][c] - tot;
			else res += board[r][c] - tot;
			board[r][c] = 0;
		}
		if (d == 1) { r -= 1;
			tot += fly(r, c, r - 2, c, 0.05);
			tot += fly(r, c, r - 1, c + 1, 0.10);
			tot += fly(r, c, r - 1, c - 1, 0.10);
			tot += fly(r, c, r, c - 2, 0.02);
			tot += fly(r, c, r, c - 1, 0.07);
			tot += fly(r, c, r, c + 1, 0.07);
			tot += fly(r, c, r, c + 2, 0.02);
			tot += fly(r, c, r + 1, c + 1, 0.01);
			tot += fly(r, c, r + 1, c - 1, 0.01);
			
			if (inBoard(r - 1, c)) board[r - 1][c] += board[r][c] - tot;
			else res += board[r][c] - tot;
			board[r][c] = 0;
		}
		if (d == 2) { c -= 1;
			tot += fly(r, c, r, c - 2, 0.05);
			tot += fly(r, c, r + 1, c - 1, 0.10);
			tot += fly(r, c, r - 1, c - 1, 0.10);
			tot += fly(r, c, r - 2, c, 0.02);
			tot += fly(r, c, r - 1, c, 0.07);
			tot += fly(r, c, r + 1, c, 0.07);
			tot += fly(r, c, r + 2, c, 0.02);
			tot += fly(r, c, r + 1, c + 1, 0.01);
			tot += fly(r, c, r - 1, c + 1, 0.01);

			if (inBoard(r, c - 1)) board[r][c - 1] += board[r][c] - tot;
			else res += board[r][c] - tot;
			board[r][c] = 0;
		}
		if (d == 3) { r += 1;
			tot += fly(r, c, r + 2, c, 0.05);
			tot += fly(r, c, r + 1, c + 1, 0.10);
			tot += fly(r, c, r + 1, c - 1, 0.10);
			tot += fly(r, c, r, c - 2, 0.02);
			tot += fly(r, c, r, c - 1, 0.07);
			tot += fly(r, c, r, c + 1, 0.07);
			tot += fly(r, c, r, c + 2, 0.02);
			tot += fly(r, c, r - 1, c + 1, 0.01);
			tot += fly(r, c, r - 1, c - 1, 0.01);

			if (inBoard(r + 1, c)) board[r + 1][c] += board[r][c] - tot;
			else res += board[r][c] - tot;
			board[r][c] = 0;
		}

		if (--t == 0) {
			d = (d + 1) % 4;
			s += 1;
			t = (s + 1) / 2;
		}

		if (r == 0 && c == -1) return;
		run();
	}
};


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) cin >> board[i][j];

	Tor T(N);
	T.run();

	cout << res;
}