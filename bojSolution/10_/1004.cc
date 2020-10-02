#include <iostream>
#include <tuple>
#define tup tuple<int,int,int>
using namespace std;

int T;
int n, res;
int xo, xt, yo, yt;
int cx, cy, cr;
tup planetary[51];

int calc(tup p) {
	bool prince, goal;
	int px = get<0>(p), py = get<1>(p), pr = get<2>(p);
	prince = ((px - xo) * (px - xo) + (py - yo) * (py - yo) < pr * pr);
	goal = ((px - xt) * (px - xt) + (py - yt) * (py - yt) < pr * pr);
	return prince^goal;
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> T;
	while (T--) {
		res = 0;

		cin >> xo >> yo >> xt >> yt;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> cx >> cy >> cr;
			planetary[i] = { cx, cy, cr };
		}
		for (int i = 0; i < n; ++i) {
			res += calc(planetary[i]);
		}
		cout << res << "\n";
	}

	return 0;
}