#include <bits/stdc++.h>
using namespace std;
int TESTS;

bool desc(int a, int b) { return (a > b); }

int n, k;
vector<int> g;
vector<int> f;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin >> TESTS;

	while (TESTS--) {
		long long res = 0;
		int lp = 0, rp = 0;
		g.clear();
		f.clear();

		cin >> n >> k;
		for (int i = 0; i < n; ++i) {
			int input; cin >> input;
			g.push_back(input);
			rp++;
		}
		sort(g.begin(), g.end());
		rp -= 1;

		for (int i = 0; i < k; ++i) {
			int input; cin >> input;
			if (input == 1) {
				res += g[rp--] * 2;
			}
			else f.push_back(input);
		}
		sort(f.begin(), f.end(), desc);

		int fSum = 0;
		for (int i = 0; i < f.size(); ++i) {
			res += g[fSum] + g[rp--];
			fSum += f[i] - 1;
		}

		cout << res << "\n";
	}

	return 0;
}
