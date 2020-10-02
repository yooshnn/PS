#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int depth, width;
int resHeight = 250;

char board[251][301]; // left bottom corner 2n, 3(n+1)
int height[50][50]; // height[i][j]: depth i, height j

int block(int depth, int h, int v) { // h, v : 1-index
	board[250 - (2 * depth + 3 * (v - 1))][2 * depth + 4 * (h - 1)] = '+';
	board[250 - (2 * depth + 3 * (v - 1))][2 * depth + 4 * (h - 1) + 1] = '-';
	board[250 - (2 * depth + 3 * (v - 1))][2 * depth + 4 * (h - 1) + 2] = '-';
	board[250 - (2 * depth + 3 * (v - 1))][2 * depth + 4 * (h - 1) + 3] = '-';
	board[250 - (2 * depth + 3 * (v - 1))][2 * depth + 4 * (h - 1) + 4] = '+';

	board[250 - (2 * depth + 3 * (v - 1)) - 1][2 * depth + 4 * (h - 1)] = '|';
	board[250 - (2 * depth + 3 * (v - 1)) - 1][2 * depth + 4 * (h - 1) + 1] = ' ';
	board[250 - (2 * depth + 3 * (v - 1)) - 1][2 * depth + 4 * (h - 1) + 2] = ' ';
	board[250 - (2 * depth + 3 * (v - 1)) - 1][2 * depth + 4 * (h - 1) + 3] = ' ';
	board[250 - (2 * depth + 3 * (v - 1)) - 1][2 * depth + 4 * (h - 1) + 4] = '|';
	board[250 - (2 * depth + 3 * (v - 1)) - 1][2 * depth + 4 * (h - 1) + 5] = '/';

	board[250 - (2 * depth + 3 * (v - 1)) - 2][2 * depth + 4 * (h - 1)] = '|';
	board[250 - (2 * depth + 3 * (v - 1)) - 2][2 * depth + 4 * (h - 1) + 1] = ' ';
	board[250 - (2 * depth + 3 * (v - 1)) - 2][2 * depth + 4 * (h - 1) + 2] = ' ';
	board[250 - (2 * depth + 3 * (v - 1)) - 2][2 * depth + 4 * (h - 1) + 3] = ' ';
	board[250 - (2 * depth + 3 * (v - 1)) - 2][2 * depth + 4 * (h - 1) + 4] = '|';
	board[250 - (2 * depth + 3 * (v - 1)) - 2][2 * depth + 4 * (h - 1) + 5] = ' ';
	board[250 - (2 * depth + 3 * (v - 1)) - 2][2 * depth + 4 * (h - 1) + 6] = '+';

	board[250 - (2 * depth + 3 * (v - 1)) - 3][2 * depth + 4 * (h - 1)] = '+';
	board[250 - (2 * depth + 3 * (v - 1)) - 3][2 * depth + 4 * (h - 1) + 1] = '-';
	board[250 - (2 * depth + 3 * (v - 1)) - 3][2 * depth + 4 * (h - 1) + 2] = '-';
	board[250 - (2 * depth + 3 * (v - 1)) - 3][2 * depth + 4 * (h - 1) + 3] = '-';
	board[250 - (2 * depth + 3 * (v - 1)) - 3][2 * depth + 4 * (h - 1) + 4] = '+';
	board[250 - (2 * depth + 3 * (v - 1)) - 3][2 * depth + 4 * (h - 1) + 5] = ' ';
	board[250 - (2 * depth + 3 * (v - 1)) - 3][2 * depth + 4 * (h - 1) + 6] = '|';

	board[250 - (2 * depth + 3 * (v - 1)) - 4][2 * depth + 4 * (h - 1) + 1] = '/';
	board[250 - (2 * depth + 3 * (v - 1)) - 4][2 * depth + 4 * (h - 1) + 2] = ' ';
	board[250 - (2 * depth + 3 * (v - 1)) - 4][2 * depth + 4 * (h - 1) + 3] = ' ';
	board[250 - (2 * depth + 3 * (v - 1)) - 4][2 * depth + 4 * (h - 1) + 4] = ' ';
	board[250 - (2 * depth + 3 * (v - 1)) - 4][2 * depth + 4 * (h - 1) + 5] = '/';
	board[250 - (2 * depth + 3 * (v - 1)) - 4][2 * depth + 4 * (h - 1) + 6] = '|';

	board[250 - (2 * depth + 3 * (v - 1)) - 5][2 * depth + 4 * (h - 1) + 2] = '+';
	board[250 - (2 * depth + 3 * (v - 1)) - 5][2 * depth + 4 * (h - 1) + 3] = '-';
	board[250 - (2 * depth + 3 * (v - 1)) - 5][2 * depth + 4 * (h - 1) + 4] = '-';
	board[250 - (2 * depth + 3 * (v - 1)) - 5][2 * depth + 4 * (h - 1) + 5] = '-';
	board[250 - (2 * depth + 3 * (v - 1)) - 5][2 * depth + 4 * (h - 1) + 6] = '+';

	return 250 - (2 * depth + 3 * (v - 1)) - 5;
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	for (int i = 0; i < 251; ++i) {
		for (int j = 0; j < 301; ++j) {
			board[i][j] = '.';
		}
	}

	cin >> depth >> width;
	for (int i = depth - 1; i >= 0; --i) {
		for (int j = 1; j <= width; ++j) {
			cin >> height[i][j];
		}
	}

	for (int i = depth - 1; i >= 0; --i) {
		for (int j = 1; j <= width; ++j) {
			for (int k = 1; k <= height[i][j]; ++k) {
				resHeight = min(resHeight, block(i, j, k));
			}
		}
	}

	for (int i = resHeight; i < 251; ++i) {
		for (int j = 0; j < 1 + 4*width + 2*depth; ++j) {
			cout << board[i][j];
		}cout << "\n";
	}

	return 0;
}