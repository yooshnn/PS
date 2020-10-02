#include <bits/stdc++.h>
#define tup tuple<int, int, char, int>
using namespace std; //int TEST;

void bfs();

int N;
int resMax = -999999, resMin = 999999;

char board[6][6];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); //cin >> TEST;

	cin >> N;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> board[i][j];
		}
	}

	bfs();

	cout << resMax << " " << resMin;

	return 0;
}

void bfs() {
	queue<tup> q;
	q.push({ 1, 1, '+', 0 });
	while (!q.empty()) {
		tup cur = q.front(); q.pop();
		int r = get<0>(cur), c = get<1>(cur), n = get<3>(cur);
		char oper = get<2>(cur);

		if ((r + c) % 2 == 0) {
			if (oper == '+') n += int(board[r][c] - '0');
			if (oper == '-') n -= int(board[r][c] - '0');
			if (oper == '*') n *= int(board[r][c] - '0');
		}
		else {
			oper = board[r][c];
		}

		if (r == N && c == N) {
			if (n > resMax) resMax = n;
			if (n < resMin) resMin = n;
			continue;
		}

		if (r < N) {
			q.push({ r + 1, c, oper, n });
		}
		if (c < N) {
			q.push({ r, c + 1, oper, n });
		}
	}
}