#include <iostream>
using namespace std;

int M, N;
bool visit[100][100];

int solve() {
	int ret = 0;
	int x = 0, y = 0, dir = 0;
	while (1) {
		if (visit[y][x]) break;
		visit[y][x] = true;

		int nx = x, ny = y;
		if (dir == 0) nx = x + 1;
		if (dir == 1) ny = y + 1;
		if (dir == 2) nx = x - 1;
		if (dir == 3) ny = y - 1;

		if (nx < 0 || ny < 0 || nx == N || ny == M || visit[ny][nx]) {
			nx = x;
			ny = y;
			ret++;
			dir += 1;
			dir %= 4;
			if (dir == 0) nx = x + 1;
			if (dir == 1) ny = y + 1;
			if (dir == 2) nx = x - 1;
			if (dir == 3) ny = y - 1;
		}
		x = nx;
		y = ny;
	}
	return ret;
}

int main() {
	cin >> M >> N;
	cout << solve() - 1;

	return 0;
}