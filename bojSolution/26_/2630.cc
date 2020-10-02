#include <iostream>
using namespace std;

int blue, white;
int paper[128][128];
void cut(int, int, int);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> paper[i][j];
		}
	}

	cut(0,0,N);
	cout << white << "\n" << blue << "\n";
	return 0;
}

void cut(int x, int y, int size) {
	int val = 0;
	for (int i = x; i < x + size; ++i) {
		for (int j = y; j < y + size; ++j) {
			val += paper[i][j];
		}
	}
	if (val == 0) {
		white++;
		return;
	}
	else if (val == size * size) {
		blue++;
		return;
	}
	else {
		cut(x, y, size / 2);
		cut(x + size / 2, y, size / 2);
		cut(x, y + size / 2, size / 2);
		cut(x + size / 2, y + size / 2, size / 2);
	}
}