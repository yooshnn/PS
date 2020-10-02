#include <bits/stdc++.h>
using namespace std;

struct snake {
	int r, c, dir;
};

int N, K, L, res = 1;
int board[102][102]; // -1 wall 0 empty 1 snake 2 apple
int input[10001];
deque<snake> s;


bool step(int frame) {
	snake head = s.front(), tail = s.back();
	bool apple = 0;
	int headDir = head.dir, cr = head.r, cc = head.c, nr = cr, nc = cc;
	if (head.dir == 0) nc++; if (head.dir == 2) nc--; if (head.dir == 1) nr++; if (head.dir == 3) nr--;
	if (board[nr][nc] == -1 || board[nr][nc] == 1) return 0;
	if (board[nr][nc] == 2) apple = true;
	s.push_front(snake{ nr, nc, (4 + headDir + input[frame]) % 4 }); board[nr][nc] = 1;
	if (apple) return 1;
	board[tail.r][tail.c] = 0;
	s.pop_back();
	return 1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i <= N + 1; ++i) { // border
		board[0][i] = -1; board[N + 1][i] = -1; board[i][0] = -1; board[i][N + 1] = -1;
	}
	for (int i = 0; i < K; ++i) { // apples
		int r, c; cin >> r >> c;
		board[r][c] = 2;
	}
	s.push_back(snake{ 1, 1, 0 });
	cin >> L;
	for (int i = 0; i < L; ++i) {
		int x; char c; cin >> x >> c;
		input[x] = (c == 'D' ? 1 : -1);
	}

	while (step(res)) {
		/*cout << res;
		if (input[res] != 0) cout << (input[res] == 1 ? " right" : " left");
		cout << "\n";
		for (int i = 0; i <= N + 1; ++i) {
			for (int j = 0; j <= N + 1; ++j) {
				if (board[i][j] == 0) cout << " ";
				else if (board[i][j] == 1) cout << "O";
				else if (board[i][j] == 2) cout << "A";
				else cout << "X";
			}
			cout << "\n";
		}
		cout << "\n";*/
		res++;
	}

	cout << res;

	return 0;
}