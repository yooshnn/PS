#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pii;
inline int input() { int num = 0, ch; while ((ch = getchar()) > 47) { num = num * 10 + (ch & 15); } return num; }

struct segt {
	int depth, f;
	ll* tree;

	segt(int n) {
		tree = new ll[n * 4];
		fill(tree, tree + n * 4, 0);
		for (depth = 1; n > (int)pow(2, depth - 1); ++depth);
		f = (int)pow(2, depth - 1) - 1;
	}
	~segt() {
		delete tree;
	}

	void build() {
		for (int i = depth - 1; i >= 1; --i) {
			for (int j = 0; j < (int)pow(2, i - 1); ++j) {
				int cur = (int)pow(2, i - 1) + j;
				tree[cur] = min(tree[cur * 2], tree[cur * 2 + 1]);
			}
		}
	}
	ll ask(int p, int q) {
		ll ret = 2147483647; p += f, q += f;
		while (p <= q) {
			if (p % 2 == 1) ret = min(ret, tree[p]);
			if (q % 2 == 0) ret = min(ret, tree[q]);
			p = (p + 1) / 2, q = (q - 1) / 2;
		}
		return ret;
	}

};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, Q, a, b; cin >> N >> Q;
	segt T(N); for (int i = 1; i <= N; ++i) cin >> T.tree[T.f + i];
	T.build();
	while (Q--) {
		cin >> a >> b;
		cout << T.ask(a, b) << "\n";
	}

}