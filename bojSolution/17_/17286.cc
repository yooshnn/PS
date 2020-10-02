#include <bits/stdc++.h>
using namespace std;

struct point {
	double x, y;
} p[4];

double res = 100000;
bool visit[4];

double getDist(point a, point b) {
	return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

void dfs(int id, int d, double r) {
	if (d == 3) {
		if (r < res) res = r;
		return;
	}

	for (int i = 1; i < 4; ++i) {
		if (visit[i]) continue;
		visit[i] = true;
		dfs(i, d + 1, r + getDist(p[id], p[i]));
		visit[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 4; ++i) cin >> p[i].x >> p[i].y;

	dfs(0, 0, 0);
	cout << int(res);

	return 0;
}