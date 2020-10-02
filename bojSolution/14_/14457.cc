#include <iostream>
using namespace std;

int N, res;
int cow[10][10];

void flip(int r, int c) {
	for (int i = 0; i <= r; ++i) {
		for (int j = 0; j <= c; ++j) {
			cow[i][j] = 1 - cow[i][j];
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			char input; cin >> input;
			cow[i][j] = (input == '1' ? 1 : 0);
		}
	}
	
	for (int i = N - 1; i >= 0; --i) {
		for (int j = N - 1; j >= 0; --j) {
			if (cow[i][j] == 1) {
				flip(i, j);
				res++;
				/*cout << "# FLIP #\n";
				for (int i = 0; i < N; ++i) {
					for (int j = 0; j < N; ++j) {
						cout << cow[i][j];
					}cout << "\n";
				}cout << "\n";*/
			}
		}
	}
	cout << res;

	return 0;
}