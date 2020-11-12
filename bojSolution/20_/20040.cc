#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline int input() { int num = 0, ch; while ((ch = getchar()) > 47) { num = num * 10 + (ch & 15); } return num; }

int par[500001];

int search(int p) {
	if (par[p] == p) return p;
	return p = search(par[p]);
}
bool merge(int p, int q) {
	p = search(p), q = search(q);
	if (p == q) return true;
	par[q] = p;
	return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) par[i] = i;

	for (int i = 1; i <= m; ++i) {
		int p, q; cin >> p >> q;
		if (merge(p, q)) {
			cout << i; return 0;
		}
	}
	cout << 0; return 0;
}