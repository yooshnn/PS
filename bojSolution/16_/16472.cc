#include <bits/stdc++.h>
using namespace std;

int n, res, visit[26];
vector<char> a;

int getV(int p) {
	return visit[a[p] - 'a'];
}
void setV(int p, int alt) {
	visit[a[p] - 'a'] += alt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	char input; while (cin >> input) a.push_back(input);

	int lp = 0, rp = 0, c = 0;
	while (rp < a.size()) {
		if (c <= n) {
			if (getV(rp) == 0) c += 1;
			if (c <= n) {
				// cout << "@ [" << lp << " : " << rp << "] c: " << c << "\n";
				res = max(res, rp - lp + 1);
			}
			setV(rp, +1);
			rp += 1;
		}
		else {
			setV(lp, -1);
			lp += 1;
			if (getV(lp - 1) == 0) c -= 1;
		}
	}

	cout << res;

	return 0;
}