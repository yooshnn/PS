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
		//fill(tree, tree + n * 4, 0);
		for (depth = 1; n > (ll)pow(2, depth - 1); ++depth);
		f = (ll)pow(2, depth - 1) - 1;
	}

	void build() {
		for (int i = depth - 1; i >= 1; --i) {
			for (int j = 0; j < (int)pow(2, i - 1); ++j) {
				int id = (int)pow(2, i - 1) + j;
				tree[id] = { min(tree[id * 2].first, tree[id * 2 + 1].first), max(tree[id * 2].second, tree[id * 2 + 1].second) };
			}
		}
	}
	void update(int id, ll val) {
		tree[f + id] = { val, val };
		id = (id + 1) / 2;
		for (int i = depth - 1; i >= 1; --i) {
			int cur = (int)pow(2, i - 1) - 1 + id;
			tree[cur] = { min(tree[cur * 2].first, tree[cur * 2 + 1].first), max(tree[cur * 2].second, tree[cur * 2 + 1].second) };
			id = (id + 1) / 2;
		}
	}
	pii ask(int p, int q) {
		pii ret = { 1000000001, 0 }; p += f, q += f;
		while (p <= q) {
			if (p % 2 == 1) ret = { min(ret.first, tree[p].first), max(ret.second, tree[p].second) };
			if (q % 2 == 0) ret = { min(ret.first, tree[q].first), max(ret.second, tree[q].second) };
			p = (p + 1) / 2, q = (q - 1) / 2;
		}
		return ret;
	}

};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, Q;
	N = input(), Q = input();

	segt T(N);

	int c;
	for (int i = 1; i <= N; ++i) {
		c = input();
		T.tree[i + T.f] = { c, c };
	}
	T.build();

	ll a, b;
	for (int i = 0; i < Q; ++i) {
		a = input(), b = input();
		pii req = T.ask(a, b);
		cout << req.first << " " << req.second << "\n";
	}
}