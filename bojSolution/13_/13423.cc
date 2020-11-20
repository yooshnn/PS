#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int TEST; cin >> TEST; while (TEST--) {
		set<int> p;
		int res = 0;
		int N; cin >> N; for (int i = 0; i < N; ++i) {
			int input; cin >> input;
			p.insert(input);
		}
		auto it = p.begin();
		do {
			auto it2 = next(it, 1);
			while (next(it2, 1) != p.end()) {
				res += bool(p.count(*it2 * 2 - *it));
				++it2;
			}
			++it;
		} while (next(it, 1) != p.end());
		cout << res << "\n";
	}
}