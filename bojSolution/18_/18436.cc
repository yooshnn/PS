#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline ll input() { ll num = 0, ch; while ((ch = getchar()) > 47) { num = num * 10 + ch - '0'; } return num; }

const ll MOD = 1000000007;

struct segt {
	int depth, f;
	ll* tree;

	segt(int n) {
		tree = new ll[n * 4];
		fill(tree, tree + n * 4, 0);
		for (depth = 1; n > (ll)pow(2, depth - 1); ++depth);
		f = (ll)pow(2, depth - 1) - 1;
	}

	void build() {
		for (int i = depth - 1; i >= 1; --i) {
			for (int j = 0; j < (int)pow(2, i - 1); ++j) {
				int id = (int)pow(2, i - 1) + j;
				tree[id] = tree[id * 2] + tree[id * 2 + 1];
			}
		}
	}
	void update(int id, ll val) {
		tree[f + id] = val;
		id = (id + 1) / 2;
		for (int i = depth - 1; i >= 1; --i) {
			int cur = (int)pow(2, i - 1) - 1 + id;
			tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
			id = (id + 1) / 2;
		}
	}
	ll ask(int p, int q) {
		ll ret = 0; p += f, q += f;
		while (p <= q) {
			if (p % 2 == 1) ret += tree[p];
			if (q % 2 == 0) ret += tree[q];
			p = (p + 1) / 2, q = (q - 1) / 2;
		}
		return ret;
	}

};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, Q;
	N = input();

	segt T(N);

	for (int i = 1; i <= N; ++i) T.tree[i + T.f] = input() % 2;
	T.build();

	Q = input();
	ll a, b, c;
	for (int i = 0; i < Q; ++i) {
		a = input(), b = input(), c = input();
		if (a == 1) T.update(b, c % 2);
		if (a == 2) cout << (c - b + 1) - T.ask(b, c) << "\n";
		if (a == 3) cout << T.ask(b, c) << "\n";
	}
}