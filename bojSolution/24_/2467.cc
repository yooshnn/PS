#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> s;
tuple<int, int, int> p{ 2100000000, -1, -1 };

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n; s.resize(n);
	for (int i = 0; i < n; ++i) cin >> s[i];

	int lp = 0, rp = s.size() - 1;
	while (lp < rp) {
		//if (lp == rp || lp == s.size() - 1 || rp == 0) break;
		int m = s[lp] + s[rp];
		if (abs(m) < abs(get<0>(p))) {
			p = { m, lp, rp };
		}
		if (m < 0) lp++;
		else rp--;
	}

	cout << s[get<1>(p)] << " " << s[get<2>(p)];


	return 0;
}