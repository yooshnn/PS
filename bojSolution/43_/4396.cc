#include <bits/stdc++.h>
using namespace std;

int N, trigger;
bool mine[12][12];
bool open[12][12];

int main() {
	cin >> N;
	for (int r = 1; r <= N; ++r) for (int c = 1; c <= N; ++c) {
		char input; cin >> input; mine[r][c] = bool(input == '*');
	}
	for (int r = 1; r <= N; ++r) for (int c = 1; c <= N; ++c) {
		char input; cin >> input; open[r][c] = bool(input == 'x');
		if (open[r][c] && mine[r][c]) trigger = 1;
	}
	
	for (int r = 1; r <= N; ++r) {
		for (int c = 1; c <= N; ++c) {
			if (trigger) {
				if (mine[r][c]) {
					cout << '*'; continue;
				}
			}
			if (open[r][c]) cout << int(mine[r][c + 1]) + mine[r - 1][c + 1] + mine[r - 1][c] + mine[r - 1][c - 1] + mine[r][c - 1] + mine[r + 1][c - 1] + mine[r + 1][c] + mine[r + 1][c + 1];
			else cout << '.';
		} cout << "\n";
	}
}