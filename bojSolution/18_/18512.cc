#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool visit[2000000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int x, y, p1, p2; cin >> x >> y >> p1 >> p2;

	while (p1 < 2000000 && p2 < 2000000) {
		if (visit[p1]) { cout << p1; return 0; }
		if (visit[p2]) { cout << p2; return 0; }
		visit[p1] = visit[p2] = true;
		p1 += x; p2 += y;
	}
	cout << -1;

	return 0;
}