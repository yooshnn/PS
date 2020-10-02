#include <bits/stdc++.h>
using namespace std;

struct component {
	int x, w, f, c;
} components[10000];

int L, N, B;
int dp[1001][1001];

bool cmpComponents(const component& l, const component& r) {
	if (l.x < r.x) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> L >> N >> B;
	for (int i = 0; i < N; ++i) {
		int x, w, f, c;
		cin >> x >> w >> f >> c;
		components[i] = {x, w, f, c};
	}
	sort(components, components + N, &cmpComponents);

	for (int i = 0; i <= L; ++i) for (int j = 0; j <= B; ++j) dp[i][j] = -1;
	for (int i = 0; i <= B; ++i) dp[0][i] = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < B; ++j) {
			if (dp[components[i].x][j] == -1) continue;
			dp[components[i].x + components[i].w][j + components[i].c] =
				max(dp[components[i].x + components[i].w][j + components[i].c], dp[components[i].x][j] + components[i].f);
		}
	}
	cout << dp[L][B];

	return 0;
}