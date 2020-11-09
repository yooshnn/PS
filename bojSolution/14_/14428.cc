#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline int input() { int num = 0, ch; while ((ch = getchar()) > 47) { num = num * 10 + ch - '0'; } return num; }

struct segt {
	int depth, f;
	pii* tree;

	segt(int n) {
		tree = new pii[n * 4];
		for (depth = 1; n > (int)pow(2, depth - 1); ++depth);
		f = (int)pow(2, depth - 1) - 1;
	}

	void build() {
		for (int i = depth - 1; i >= 1; --i) {
			for (int j = 0; j < (int)pow(2, i - 1); ++j) {
				int cur = (int)pow(2, i - 1) + j;
				tree[cur] =
					(tree[cur * 2] <= tree[cur * 2 + 1] ? tree[cur * 2] : tree[cur * 2 + 1]);
			}
		}
	}
	void update(int id, ll val) {
		tree[f + id] = { val, id };
		id = (id + 1) / 2;
		for (int i = depth - 1; i >= 1; --i) {
			int cur = (int)pow(2, i - 1) - 1 + id;
			tree[cur] =
				(tree[cur * 2] <= tree[cur * 2 + 1] ? tree[cur * 2] : tree[cur * 2 + 1]);
			id = (id + 1) / 2;
		}
	}
	int ask(int p, int q) {
		pii ret = { 2147483647, 1 }; p += f, q += f;
		while (p <= q) {
			if (p % 2 == 1) ret =
				(ret <= tree[p] ? ret : tree[p]);
			if (q % 2 == 0) ret =
				(ret <= tree[q] ? ret : tree[q]);
			p = (p + 1) / 2, q = (q - 1) / 2;
		}
		return ret.second;
	}

};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, Q;
	N = input();

	segt T(N);

	for (int i = 1; i <= N; ++i) T.tree[i + T.f] = { input(), i };
	T.build();

	Q = input();
	ll a, b, c;
	for (int i = 0; i < Q; ++i) {
		a = input(), b = input(), c = input();
		if (a == 1) T.update(b, c);
		if (a == 2) cout << T.ask(b, c) << "\n";
	}
}