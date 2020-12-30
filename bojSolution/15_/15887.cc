#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int N; cin >> N; vector<int> v(N);
	for (int& x : v) cin >> x, x--;

	vector<pii> res;
	for (int i = 0; i < N; ++i) {
		if (v[i] != i) {
			int p = i;
			while (v[p] != i) p++;
			for (int k = 0; k <= (p-i)/2; ++k) {
				swap(v[i+k], v[p-k]);
			}
			res.push_back({i+1, p+1});
		}
	}

	cout << res.size() << '\n';
	for (pii& p : res) cout << p.first << ' ' << p.second << '\n';

	//cout << endl; system("pause");
}