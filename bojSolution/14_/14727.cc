#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
inline int input() { int num = 0, ch; while ((ch = getchar()) > 47) { num = num * 10 + (ch & 15); } return num; }

struct segt {
	int depth, f;
	pii* tree;

	segt(int n) {
		tree = new pii[n * 4];
		//fill(tree, tree + n * 4, 0);
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
				if (tree[cur * 2].first < tree[cur * 2 + 1].first) tree[cur] = tree[cur * 2];
				else tree[cur] = tree[cur * 2 + 1];
			}
		}
	}

	pii ask(int p, int q) {
		pii ret = { 2147483647, -1 }; p += f, q += f;
		while (p <= q) {
			if (p % 2 == 1) {
				if (ret.first == tree[p].first) ret = { ret.first, max(ret.second, tree[p].second) };
				else ret = (ret.first < tree[p].first ? ret : tree[p]);
			}
			if (q % 2 == 0) {
				if (ret.first == tree[q].first) ret = { ret.first, max(ret.second, tree[q].second) };
				else ret = (ret.first < tree[q].first ? ret : tree[q]);
			}
			p = (p + 1) / 2, q = (q - 1) / 2;
		}
		return ret;
	}

};

ll query(segt& T, int N, int p, int q) {
	pii req = T.ask(p, q);
	//cout << "p : " << p << ", q : " << q << "\n";
	ll ret = ll(q - p + 1) * req.first;

	if (p < req.second) ret = max(ret, query(T, N, p, req.second - 1));
	if (q > req.second) ret = max(ret, query(T, N, req.second + 1, q));

	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (1) {
		int N; cin >> N; if (N == 0) break;
		segt T(N);
		ll maxh = 0;
		for (int i = 1; i <= N; ++i) {
			ll t; cin >> t;
			T.tree[i + T.f] = { t, i };
			maxh = max(maxh, t);
		}
		T.build();

		cout << query(T, N, 1, N) << "\n";
		
		break;
	}
}