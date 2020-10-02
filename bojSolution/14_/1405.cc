#include <iostream>
#include <iomanip>
using namespace std;

int N;
double prob[4];
bool dup[29][29];

double solve(int depth, int x, int y) {
	if (depth == N) {
		return 1;
	}

	double res = 0;
	dup[y][x] = true;
	for (int i = 0; i < 4; ++i) {
		int nx = x + (i == 0) - (i == 1);
		int ny = y + (i == 2) - (i == 3);
		if (dup[ny][nx]) continue;
		res += prob[i] * solve(depth + 1, nx, ny);
	}
	dup[y][x] = false;
	return res;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);

	cin >> N >> prob[0] >> prob[1] >> prob[2] >> prob[3];
	for (int i = 0; i < 4; ++i) prob[i] /= 100;

	cout << fixed << setprecision(9) << solve(0, 14, 14);

	return 0;
}