#include <iostream>
using namespace std;

int N, M;
int S, E;
int num[2001];
bool palindrome[2001][2001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);
	
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> num[i];
	}

	for (int i = 1; i <= N; ++i) {
		palindrome[i][i] = true;
		if ((i != N) && (num[i] == num[i + 1])) palindrome[i][i + 1] = true;
	}
	for (int i = 2; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			if (j + i > 2000) break;
			if (palindrome[j + 1][j + i - 1] && num[j] == num[j + i]) palindrome[j][j + i] = true;
		}
	}

	cin >> M;
	for (int i = 1; i <= M; ++i) {
		cin >> S >> E;
		cout << palindrome[S][E] << "\n";
	}

	return 0;
}