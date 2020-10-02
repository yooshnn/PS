#include <iostream>
#include <vector>
using namespace std;

int N;
int p[3]{ 0,0,0 };
vector<vector<short int>>paper;

void cut(int x, int y, int size) {
	if (size == 1) {
		p[paper[y][x]+1]++;
		return;
	}
	// 지금 주어진 종이가 한 종류로 꽉 찼는가?
	int parse[3]{ 0,0,0 };
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			parse[paper[y+i][x+j]+1]++;
		}
	}
	for (int i = 0; i < 3; ++i) {
		if (parse[i] == size * size) {
			p[i]++;
			return;
		}
	}
	// 아니면 분할
	int nsize = size / 3;
	cut(x, y, nsize);
	cut(x + nsize, y, nsize);
	cut(x + 2 * nsize, y, nsize);
	cut(x, y + nsize, nsize);
	cut(x + nsize, y + nsize, nsize);
	cut(x + 2 * nsize, y + nsize, nsize);
	cut(x, y + 2*nsize, nsize);
	cut(x + nsize, y + 2*nsize, nsize);
	cut(x + 2 * nsize, y + 2*nsize, nsize);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		vector<short int> line;
		short int input;
		for (int j = 0; j < N; ++j) {
			cin >> input;
			line.push_back(input);
		}
		paper.push_back(line);
	}

	cut(0, 0, N);
	cout << p[0] << "\n" << p[1] << "\n" << p[2];

	return 0;
}