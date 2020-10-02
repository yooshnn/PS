#include <iostream>
using namespace std;

int m1[100][100];
int m2[100][100];
int m3[100][100] = { 0, };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int N, M, K, input;

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> m1[i][j];
		}
	}
	cin >> M >> K;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < K; ++j) {
			cin >> m2[j][i];
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < K; ++j) {
			int val = 0;
			for (int k = 0; k < M; ++k) {
				val += m1[i][k] * m2[j][k];
			}
			cout << val << " ";
		}
		cout << "\n";
	}

	return 0;
}